<?php

/**
 * @file
 * Adds default views.
 */

/**
 * Implements hook_views_default_views().
 */
function fontyourface_ui_views_default_views() {
  /*
   * View 'fontyourface_browse'
   */
  $view = new view;
  $view->name = 'fontyourface_browse';
  $view->description = 'Browsing interface for fonts.';
  $view->tag = '@font-your-face';
  $view->base_table = 'fontyourface_font';
  $view->human_name = '@font-your-face Browse';
  $view->core = 0;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Browse fonts';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer @font-your-face';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '5';
  $handler->display->display_options['style_options']['fill_single_line'] = 1;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '0 fonts currently enabled.';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['header']['area']['tokenize'] = 0;
  /* Relationship: Font: Font Tag */
  $handler->display->display_options['relationships']['tid']['id'] = 'tid';
  $handler->display->display_options['relationships']['tid']['table'] = 'fontyourface_tag_font';
  $handler->display->display_options['relationships']['tid']['field'] = 'tid';
  $handler->display->display_options['relationships']['tid']['required'] = 0;
  /* Field: Font: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'fontyourface_font';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['label'] = '';
  $handler->display->display_options['fields']['name_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name_1']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['name_1']['alter']['text'] = '<span>Edit</span>';
  $handler->display->display_options['fields']['name_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name_1']['element_type'] = '0';
  $handler->display->display_options['fields']['name_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name_1']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['name_1']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['name_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name_1']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['name_1']['link_to_font'] = 'edit';
  $handler->display->display_options['fields']['name_1']['display_as'] = '0';
  /* Field: Font: Font ID */
  $handler->display->display_options['fields']['fid']['id'] = 'fid';
  $handler->display->display_options['fields']['fid']['table'] = 'fontyourface_font';
  $handler->display->display_options['fields']['fid']['field'] = 'fid';
  $handler->display->display_options['fields']['fid']['label'] = '';
  $handler->display->display_options['fields']['fid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['fid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['fid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['fid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['fid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['fid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['fid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['fid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['fid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['fid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['fid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['fid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['fid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['fid']['element_type'] = '0';
  $handler->display->display_options['fields']['fid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['fid']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['fid']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['fid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['fid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['fid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['fid']['separator'] = '';
  $handler->display->display_options['fields']['fid']['format_plural'] = 0;
  /* Field: Font: Enabled */
  $handler->display->display_options['fields']['enabled']['id'] = 'enabled';
  $handler->display->display_options['fields']['enabled']['table'] = 'fontyourface_font';
  $handler->display->display_options['fields']['enabled']['field'] = 'enabled';
  $handler->display->display_options['fields']['enabled']['label'] = '';
  $handler->display->display_options['fields']['enabled']['exclude'] = TRUE;
  $handler->display->display_options['fields']['enabled']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['enabled']['alter']['text'] = '<div class="fontyourface-container enabled-[enabled]">';
  $handler->display->display_options['fields']['enabled']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['enabled']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['enabled']['alter']['external'] = 0;
  $handler->display->display_options['fields']['enabled']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['enabled']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['enabled']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['enabled']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['enabled']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['enabled']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['enabled']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['enabled']['alter']['html'] = 0;
  $handler->display->display_options['fields']['enabled']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['enabled']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['enabled']['hide_empty'] = 0;
  $handler->display->display_options['fields']['enabled']['empty_zero'] = 0;
  $handler->display->display_options['fields']['enabled']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['enabled']['not'] = 0;
  /* Field: Font: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'fontyourface_font';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['name']['alter']['text'] = '<div class="fontyourface-header"><h4>[name]</h4> [name_1]</div>';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_type'] = '0';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['name']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['name']['link_to_font'] = '0';
  $handler->display->display_options['fields']['name']['display_as'] = '0';
  /* Field: Font: Enable/Disable */
  $handler->display->display_options['fields']['enable_disable_link']['id'] = 'enable_disable_link';
  $handler->display->display_options['fields']['enable_disable_link']['table'] = 'fontyourface_font';
  $handler->display->display_options['fields']['enable_disable_link']['field'] = 'enable_disable_link';
  $handler->display->display_options['fields']['enable_disable_link']['label'] = '';
  $handler->display->display_options['fields']['enable_disable_link']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['enable_disable_link']['alter']['text'] = '<div class="fontyourface-footer enabled-[enabled]" data-fid="[fid]">[enable_disable_link]</div>';
  $handler->display->display_options['fields']['enable_disable_link']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['enable_disable_link']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['enable_disable_link']['alter']['external'] = 0;
  $handler->display->display_options['fields']['enable_disable_link']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['enable_disable_link']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['enable_disable_link']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['enable_disable_link']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['enable_disable_link']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['enable_disable_link']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['enable_disable_link']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['enable_disable_link']['alter']['html'] = 0;
  $handler->display->display_options['fields']['enable_disable_link']['element_type'] = '0';
  $handler->display->display_options['fields']['enable_disable_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['enable_disable_link']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['enable_disable_link']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['enable_disable_link']['hide_empty'] = 0;
  $handler->display->display_options['fields']['enable_disable_link']['empty_zero'] = 0;
  $handler->display->display_options['fields']['enable_disable_link']['hide_alter_empty'] = 0;
  /* Field: Font: Preview */
  $handler->display->display_options['fields']['preview']['id'] = 'preview';
  $handler->display->display_options['fields']['preview']['table'] = 'fontyourface_font';
  $handler->display->display_options['fields']['preview']['field'] = 'preview';
  $handler->display->display_options['fields']['preview']['label'] = '';
  $handler->display->display_options['fields']['preview']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['preview']['alter']['text'] = '<div class="fontyourface-preview enabled-[enabled]">[preview]</div>';
  $handler->display->display_options['fields']['preview']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['preview']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['preview']['alter']['external'] = 0;
  $handler->display->display_options['fields']['preview']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['preview']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['preview']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['preview']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['preview']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['preview']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['preview']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['preview']['alter']['html'] = 0;
  $handler->display->display_options['fields']['preview']['element_type'] = '0';
  $handler->display->display_options['fields']['preview']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['preview']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['preview']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['preview']['hide_empty'] = 0;
  $handler->display->display_options['fields']['preview']['empty_zero'] = 0;
  $handler->display->display_options['fields']['preview']['hide_alter_empty'] = 0;
  /* Sort criterion: Font: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'fontyourface_font';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  /* Filter criterion: Font: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'fontyourface_font';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['operator'] = 'contains';
  $handler->display->display_options['filters']['name']['group'] = 0;
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  /* Filter criterion: Font: Tag ID */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'fontyourface_tag';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['relationship'] = 'tid';
  $handler->display->display_options['filters']['tid']['group'] = 0;
  $handler->display->display_options['filters']['tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid']['expose']['operator_id'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['label'] = 'Tags';
  $handler->display->display_options['filters']['tid']['expose']['operator'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['identifier'] = 'tid';
  $handler->display->display_options['filters']['tid']['expose']['required'] = FALSE;
  $handler->display->display_options['filters']['tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  /* Filter criterion: Font: Provider */
  $handler->display->display_options['filters']['provider']['id'] = 'provider';
  $handler->display->display_options['filters']['provider']['table'] = 'fontyourface_font';
  $handler->display->display_options['filters']['provider']['field'] = 'provider';
  $handler->display->display_options['filters']['provider']['group'] = 0;
  $handler->display->display_options['filters']['provider']['exposed'] = TRUE;
  $handler->display->display_options['filters']['provider']['expose']['operator_id'] = 'provider_op';
  $handler->display->display_options['filters']['provider']['expose']['label'] = 'Provider';
  $handler->display->display_options['filters']['provider']['expose']['operator'] = 'provider_op';
  $handler->display->display_options['filters']['provider']['expose']['identifier'] = 'provider';
  $handler->display->display_options['filters']['provider']['expose']['reduce'] = 0;
  /* Filter criterion: Font: Foundry */
  $handler->display->display_options['filters']['foundry']['id'] = 'foundry';
  $handler->display->display_options['filters']['foundry']['table'] = 'fontyourface_font';
  $handler->display->display_options['filters']['foundry']['field'] = 'foundry';
  $handler->display->display_options['filters']['foundry']['group'] = 0;
  $handler->display->display_options['filters']['foundry']['exposed'] = TRUE;
  $handler->display->display_options['filters']['foundry']['expose']['operator_id'] = 'foundry_op';
  $handler->display->display_options['filters']['foundry']['expose']['label'] = 'Foundry';
  $handler->display->display_options['filters']['foundry']['expose']['operator'] = 'foundry_op';
  $handler->display->display_options['filters']['foundry']['expose']['identifier'] = 'foundry';
  $handler->display->display_options['filters']['foundry']['expose']['reduce'] = 0;
  /* Filter criterion: Font: License */
  $handler->display->display_options['filters']['license']['id'] = 'license';
  $handler->display->display_options['filters']['license']['table'] = 'fontyourface_font';
  $handler->display->display_options['filters']['license']['field'] = 'license';
  $handler->display->display_options['filters']['license']['operator'] = 'contains';
  $handler->display->display_options['filters']['license']['group'] = 0;
  $handler->display->display_options['filters']['license']['exposed'] = TRUE;
  $handler->display->display_options['filters']['license']['expose']['operator_id'] = 'license_op';
  $handler->display->display_options['filters']['license']['expose']['label'] = 'License';
  $handler->display->display_options['filters']['license']['expose']['operator'] = 'license_op';
  $handler->display->display_options['filters']['license']['expose']['identifier'] = 'license';
  $handler->display->display_options['filters']['license']['expose']['required'] = 0;
  $handler->display->display_options['filters']['license']['expose']['multiple'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'admin/appearance/fontyourface/browse';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Browse';
  $handler->display->display_options['menu']['weight'] = '0';
  $translatables['fontyourface_browse'] = array(
    t('Defaults'),
    t('Browse fonts'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('0 fonts currently enabled.'),
    t('Font Tag'),
    t('<span>Edit</span>'),
    t('.'),
    t('<div class="fontyourface-container enabled-[enabled]">'),
    t('<div class="fontyourface-header"><h4>[name]</h4> [name_1]</div>'),
    t('<div class="fontyourface-footer enabled-[enabled]" data-fid="[fid]">[enable_disable_link]</div>'),
    t('<div class="fontyourface-preview enabled-[enabled]">[preview]</div>'),
    t('Name'),
    t('Tags'),
    t('Provider'),
    t('Foundry'),
    t('License'),
    t('Page'),
  );

  $views[$view->name] = $view;

  return $views;

} // fontyourface_ui_views_default_views
