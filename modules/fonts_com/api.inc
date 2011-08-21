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
 * Gets a list of all fonts, in given range.
 */
function fonts_com_get_all_fonts($start = 0, $limit = 100) {

  $fonts = array();

  $path = '/rest/json/AllFonts/?wfspstart=' . $start . '&wfsplimit=' . $limit;

  $response = drupal_http_request(FONTS_COM_API_BASE_URL . $path, array('headers' => fonts_com_api_headers($path)));

  if ($response->code == 200) {

    $data = json_decode($response->data);
    $font = $data->AllFonts->Font;
    $fonts = fonts_com_unknown_to_array($font);

  } // if
  else {

    drupal_set_message(t('There was an error importing a font list from Fonts.com.'), 'error');
    fontyourface_log('Invalid drupal_http_request response: @response', array('@response' => print_r($response, TRUE)));

  } // else

  return $fonts;

} // fonts_com_get_all_fonts

/**
 * Gets total font count.
 */
function fonts_com_get_all_fonts_count() {

  $path = '/rest/json/AllFonts/?wfspstart=0&wfsplimit=1';

  $response = drupal_http_request(FONTS_COM_API_BASE_URL . $path, array('headers' => fonts_com_api_headers($path)));

  if ($response->code == 200) {

    $data = json_decode($response->data);
    return $data->AllFonts->TotalRecords;

  } // if

  drupal_set_message(t('There was an error importing the font count from Fonts.com.'), 'error');
  fontyourface_log('Invalid drupal_http_request response: @response', array('@response' => print_r($response, TRUE)));

  return FALSE;

} // fonts_com_get_all_fonts_count

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
 * Saves list of domains in a given project.
 */
function fonts_com_save_domains_in_project($project_id, $new_domains) {

  $old_domains = array();
  $domain_to_index = array();

  $old_domain_objects = fonts_com_get_domains_in_project($project_id);

  foreach ($old_domain_objects as $index => $old_domain_object) {

    $domain_to_index[$old_domain_object->DomainName] = $index;
    $old_domains[] = $old_domain_object->DomainName;

  } // foreach

  $add_domains = array_diff($new_domains, $old_domains);
  $delete_domains = array_diff($old_domains, $new_domains);

  foreach ($delete_domains as $delete_domain) {

    $delete_domain_object = $old_domain_objects[$domain_to_index[$delete_domain]];
    fonts_com_delete_domain($project_id, $delete_domain_object->DomainID);

  } // foreach

  foreach ($add_domains as $add_domain) {
    fonts_com_add_domain($project_id, $add_domain);
  } // foreach

} // fonts_com_save_domains_in_project

/**
 * Deletes a single domain in a project.
 */
function fonts_com_delete_domain($project_id, $domain_id) {

  $path = '/rest/json/Domains/?wfspid=' . $project_id . '&wfsdomain_id=' . $domain_id;

  $response = drupal_http_request(FONTS_COM_API_BASE_URL . $path, array('headers' => fonts_com_api_headers($path), 'method' => 'DELETE'));

  if ($response->code == 200) {
    return TRUE;
  } // if
  else {

    drupal_set_message(t('There was an error deleting a domain (@domain) in a project (@project) on Fonts.com.', array('@domain' => $domain_id, '@project' => $project_id)), 'error');
    fontyourface_log('Invalid drupal_http_request response: @response', array('@response' => print_r($response, TRUE)));

  } // else

  return FALSE;

} // fonts_com_delete_domain

/**
 * Adds a single domain to a project.
 */
function fonts_com_add_domain($project_id, $domain_name) {

  $path = '/rest/json/Domains/?wfspid=' . $project_id;

  $response = drupal_http_request(FONTS_COM_API_BASE_URL . $path, array('headers' => fonts_com_api_headers($path), 'method' => 'POST', 'data' => 'wfsdomain_name=' . $domain_name));

  if ($response->code == 200) {
    return TRUE;
  } // if
  else {

    drupal_set_message(t('There was an error adding a domain (@domain) in a project (@project) on Fonts.com.', array('@domain' => $domain_name, '@project' => $project_id)), 'error');
    fontyourface_log('Invalid drupal_http_request response: @response', array('@response' => print_r($response, TRUE)));

  } // else

  return FALSE;

} // fonts_com_add_domain

/**
 * Gets list of projects from API.
 */
function fonts_com_get_projects() {

  $projects = array();

  $path = '/rest/json/Projects/?wfspstart=0&wfsplimit=100';

  $response = drupal_http_request(FONTS_COM_API_BASE_URL . $path, array('headers' => fonts_com_api_headers($path)));

  if ($response->code == 200) {

    $data = json_decode($response->data);

    if ($data->Projects->TotalRecords > 0) {

      $project = $data->Projects->Project;
      $projects = fonts_com_unknown_to_array($project);

    } // if

  } // if
  else {

    drupal_set_message(t('There was an error importing project list from Fonts.com.'), 'error');
    fontyourface_log('Invalid drupal_http_request response: @response', array('@response' => print_r($response, TRUE)));

  } // else

  return $projects;

} // fonts_com_get_projects

/**
 * Gets list of projects from API.
 */
function fonts_com_get_project_by_id($project_id) {

  $projects = fonts_com_get_projects();

  if (count($projects) > 0) {

    foreach ($projects as $project) {

        if ($project->ProjectKey == $project_id) {
          return $project;
        } // if

      } // foreach

  } // if

  return FALSE;

} // fonts_com_get_project_by_id

/**
 * Update.
 */
function fonts_com_save_project($project) {

  $path = '/rest/json/Projects/';
  $method = 'POST';

  if (isset($project->ProjectKey)) {

    $path .= '?wfspid=' . $project->ProjectKey;
    $method = 'PUT';

  } // if

  $response = drupal_http_request(FONTS_COM_API_BASE_URL . $path, array('headers' => fonts_com_api_headers($path), 'method' => $method, 'data' => 'wfsproject_name=' . $project->ProjectName));

  if ($response->code == 200) {

    return TRUE;

  } // if
  else {

    drupal_set_message(t('There was an error saving project to Fonts.com.'), 'error');
    fontyourface_log('Invalid drupal_http_request response: @response', array('@response' => print_r($response, TRUE)));

  } // else

  return FALSE;

} // fonts_com_save_project

/**
 * Adds font to project.
 */
function fonts_com_add_font_to_project($font_id, $project_id) {

  $path = '/rest/json/Fonts/?wfspid=' . $project_id;

  $response = drupal_http_request(FONTS_COM_API_BASE_URL . $path, array('headers' => fonts_com_api_headers($path), 'method' => 'POST', 'data' => 'wfsfid=' . $font_id));

  if ($response->code == 200) {

    $data = json_decode($response->data);
    return TRUE;

  } // if
  else {

    drupal_set_message(t('There was an error enabling the font on Fonts.com.'), 'error');
    fontyourface_log('Invalid drupal_http_request response: @response', array('@response' => print_r($response, TRUE)));

  } // else

  return FALSE;

} // fonts_com_add_font_to_project

/**
 * Deletes font from project.
 */
function fonts_com_delete_font_from_project($font_id, $project_id) {

  $path = '/rest/json/Fonts/?wfspid=' . $project_id . '&wfsfid=' . $font_id;

  $response = drupal_http_request(FONTS_COM_API_BASE_URL . $path, array('headers' => fonts_com_api_headers($path), 'method' => 'DELETE'));

  if ($response->code == 200) {

    return TRUE;

  } // if
  else {

    drupal_set_message(t('There was an error disabling the font on Fonts.com.'), 'error');
    fontyourface_log('Invalid drupal_http_request response: @response', array('@response' => print_r($response, TRUE)));

  } // else

  return FALSE;

} // fonts_com_delete_font_from_project

/**
 * Provides headers with api parameters.
 */
function fonts_com_api_headers($path) {

  list($public_key, $private_key) = explode('--', variable_get('fonts_com_token', ''));

  $encoded = base64_encode(hash_hmac('md5', $public_key . '|' . $path, $private_key, TRUE));
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
