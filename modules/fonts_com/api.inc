<?php

/**
 * @file
 * API functions.
 */

define('FONTS_COM_API_BASE_URL', 'https://api.fonts.com');
define('FONTS_COM_API_APP_KEY', '1fdb130c-d5c0-4fab-8e2b-271508570323932606');

/**
 * Gets list of fonts in a given project.
 */
function fonts_com_get_fonts_in_project($project_id) {

  $fonts = array();

  $path = '/rest/json/Fonts/?wfspstart=0&wfsplimit=100&wfspid=' . $project_id;

  $response = drupal_http_request(FONTS_COM_API_BASE_URL . $path, array('headers' => fonts_com_api_headers($path)));

  if ($response->code == 200) {

    $data = json_decode($response->data);
    $font = $data->Fonts->Font;
    $fonts = fonts_com_unknown_to_array($font);

  } // if
  else {

    drupal_set_message(t('There was an error importing a project (@project) font list from Fonts.com.', array('@project' => $project_id)), 'error');
    fontyourface_log('Invalid drupal_http_request response: @response', array('@response' => print_r($response, TRUE)));

  } // else

  return $fonts;

} // fonts_com_get_fonts_in_project

/**
 * Gets auth key for a given account.
 */
function fonts_com_get_key_for_account($email, $password) {

  $key = FALSE;

  $path = '/rest/json/Accounts/?wfsemail=' . $email;

  $response = drupal_http_request(FONTS_COM_API_BASE_URL . $path, array('headers' => array('AppKey' => FONTS_COM_API_APP_KEY, 'Password' => $password)));

  if ($response->code == 200) {

    $data = json_decode($response->data);

    if (
      isset($data->Accounts) && 
      isset($data->Accounts->Account) && 
      isset($data->Accounts->Account->AuthorizationKey)
    ) {

      $key = $data->Accounts->Account->AuthorizationKey;

    } // if
    else {

      drupal_set_message(t('The submitted email and password were not recognized by Fonts.com.'), 'error');
      fontyourface_log('Invalid drupal_http_request response: @response', array('@response' => print_r($response, TRUE)));

    } // else

  } // if
  else {

    drupal_set_message(t('There was an error getting your key from Fonts.com.'), 'error');
    fontyourface_log('Invalid drupal_http_request response: @response', array('@response' => print_r($response, TRUE)));

  } // else

  return $key;

} // fonts_com_get_key_for_account

/**
 * Creates a new account.
 */
function fonts_com_create_account($email, $first_name, $last_name) {

  $success = FALSE;

  $path = '/rest/json/Accounts/';

  $response = drupal_http_request(FONTS_COM_API_BASE_URL . $path, array('headers' => array('AppKey' => FONTS_COM_API_APP_KEY), 'method' => 'POST', 'data' => 'wfsfirst_name=' . $first_name . '&wfslast_name=' . $last_name . '&wfsemail=' . $email));

  if ($response->code == 200) {

    $data = json_decode($response->data);

    if (
      isset($data->Accounts) && 
      isset($data->Accounts->Message) &&
      ($data->Accounts->Message == 'Success')
    ) {

      $success = TRUE;

    } // if
    else {

      drupal_set_message(t('Fonts.com as unable to create your account.'), 'error');
      fontyourface_log('Invalid drupal_http_request response: @response', array('@response' => print_r($response, TRUE)));

    } // else

  } // if
  else {

    drupal_set_message(t('There was an error creating an account at Fonts.com.'), 'error');
    fontyourface_log('Invalid drupal_http_request response: @response', array('@response' => print_r($response, TRUE)));

  } // else

  return $success;

} // fonts_com_create_account

/**
 * Gets list of domains in a given project.
 */
function fonts_com_get_domains_in_project($project_id) {

  $domains = array();

  $path = '/rest/json/Domains/?wfspstart=0&wfsplimit=100&wfspid=' . $project_id;

  $response = drupal_http_request(FONTS_COM_API_BASE_URL . $path, array('headers' => fonts_com_api_headers($path)));

  if ($response->code == 200) {

    $data = json_decode($response->data);

    if ($data->Domains->TotalRecords > 0) {

      $domain = $data->Domains->Domain;
      $domains = fonts_com_unknown_to_array($domain);

    } // if

  } // if
  else {

    drupal_set_message(t('There was an error importing a project (@project) domain list from Fonts.com.', array('@project' => $project_id)), 'error');
    fontyourface_log('Invalid drupal_http_request response: @response', array('@response' => print_r($response, TRUE)));

  } // else

  return $domains;

} // fonts_com_get_domains_in_project

/**
 * Gets list of projects from API.
 */
function fonts_com_get_projects() {

  $projects = array();

  $path = '/rest/json/Projects/?wfspstart=0&wfsplimit=100';

  $response = drupal_http_request(FONTS_COM_API_BASE_URL . $path, array('headers' => fonts_com_api_headers($path)));

  if ($response->code == 200) {

    $data = json_decode($response->data);
    $project = $data->Projects->Project;
    $projects = fonts_com_unknown_to_array($project);

  } // if
  else {

    drupal_set_message(t('There was an error importing project list from Fonts.com.'), 'error');
    fontyourface_log('Invalid drupal_http_request response: @response', array('@response' => print_r($response, TRUE)));

  } // else

  return $projects;

} // fonts_com_get_projects

/**
 * Provides headers with api parameters.
 */
function fonts_com_api_headers($path) {

  list($public_key, $private_key) = explode('--', variable_get('fonts_com_token', ''));

  $encoded = base64_encode(hash_hmac('md5', $public_key . '|' . $path, $private_key, true));
  $auth = urlencode($public_key . ':' . $encoded);

  return array('Authorization' => $auth, 'AppKey' => FONTS_COM_API_APP_KEY);

} // fonts_com_api_headers

/**
 * Returns an array, regardless of input.
 */
function fonts_com_unknown_to_array($unknown) {

  if (is_array($unknown)) {
    return $unknown;
  } // if

  return array($unknown);

} // fonts_com_unknown_to_array
