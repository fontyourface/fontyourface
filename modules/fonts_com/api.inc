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

  $logging = variable_get('fontyourface_detailed_logging', FALSE);

  $fonts = array();

  $path = '/rest/json/Fonts/?wfspstart=0&wfsplimit=100&wfspid=' . $project_id;

  $response = drupal_http_request(FONTS_COM_API_BASE_URL . $path, array('headers' => fonts_com_api_headers($path)));

  if ($response->code == 200) {

    $data = json_decode($response->data);
    $font = $data->Fonts->Font;

    if (is_array($font)) {
      $fonts = $font;
    } // if
    else {
      $fonts[] = $font;
    } // else

  } // if
  else {

    drupal_set_message(t('There was an error importing a project (@project) font list from Fonts.com.', array('@project' => $project_id)), 'error');

    if ($logging) {
      watchdog('@font-your-face', 'Invalid drupal_http_request response: @response', array('@response' => print_r($response, TRUE)), WATCHDOG_INFO);
    } // if

  } // else

  return $fonts;

} // fonts_com_get_fonts_in_project

/**
 * Gets auth key for a given account.
 */
function fonts_com_get_key_for_account($email, $password) {

  $logging = variable_get('fontyourface_detailed_logging', FALSE);

  $key = '';

  $path = '/rest/json/Accounts/?wfsemail=' . $email;

  $response = drupal_http_request(FONTS_COM_API_BASE_URL . $path, array('headers' => array('AppKey' => FONTS_COM_API_APP_KEY, 'Password' => $password)));

  if ($response->code == 200) {

    $data = json_decode($response->data);

    dpm($data);
    dpm($response);

  } // if
  else {

    drupal_set_message(t('There was an error getting your key from Fonts.com.'), 'error');

    if ($logging) {
      watchdog('@font-your-face', 'Invalid drupal_http_request response: @response', array('@response' => print_r($response, TRUE)), WATCHDOG_INFO);
    } // if

  } // else

  return $key;

} // fonts_com_get_key_for_account

/**
 * Gets list of domains in a given project.
 */
function fonts_com_get_domains_in_project($project_id) {

  $logging = variable_get('fontyourface_detailed_logging', FALSE);

  $domains = array();

  $path = '/rest/json/Domains/?wfspstart=0&wfsplimit=100&wfspid=' . $project_id;

  $response = drupal_http_request(FONTS_COM_API_BASE_URL . $path, array('headers' => fonts_com_api_headers($path)));

  if ($response->code == 200) {

    $data = json_decode($response->data);

    if ($data->Domains->TotalRecords > 0) {

      $domain = $data->Domains->Domain;
  
      if (is_array($domain)) {
        $domains = $domain;
      } // if
      else {
        $domains[] = $domain;
      } // else

    } // if

  } // if
  else {

    drupal_set_message(t('There was an error importing a project (@project) domain list from Fonts.com.', array('@project' => $project_id)), 'error');

    if ($logging) {
      watchdog('@font-your-face', 'Invalid drupal_http_request response: @response', array('@response' => print_r($response, TRUE)), WATCHDOG_INFO);
    } // if

  } // else

  return $domains;

} // fonts_com_get_domains_in_project

/**
 * Gets list of projects from API.
 */
function fonts_com_get_projects() {

  $logging = variable_get('fontyourface_detailed_logging', FALSE);

  $projects = array();

  $path = '/rest/json/Projects/?wfspstart=0&wfsplimit=100';

  $response = drupal_http_request(FONTS_COM_API_BASE_URL . $path, array('headers' => fonts_com_api_headers($path)));

  if ($response->code == 200) {

    $data = json_decode($response->data);
    $project = $data->Projects->Project;
    
    if (is_array($project)) {
      $projects = $project;
    } // if
    else {
      $projects[] = $project;
    } // else

  } // if
  else {

    drupal_set_message(t('There was an error importing project list from Fonts.com.'), 'error');

    if ($logging) {
      watchdog('@font-your-face', 'Invalid drupal_http_request response: @response', array('@response' => print_r($response, TRUE)), WATCHDOG_INFO);
    } // if

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
