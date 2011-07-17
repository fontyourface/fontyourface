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
  $handler->display->display_options['pager']['options']['items_per_page'] = 25;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '5';
  $handler->display->display_options['style_options']['fill_single_line'] = 1;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['text']['id'] = 'area';
  $handler->display->display_options['header']['text']['table'] = 'views';
  $handler->display->display_options['header']['text']['field'] = 'area';
  $handler->display->display_options['header']['text']['empty'] = FALSE;
  $handler->display->display_options['header']['text']['content'] = 'Click a font name to view details and add the font.';
  $handler->display->display_options['header']['text']['format'] = '1';
  /* Relationship: Font: Font Tag */
  $handler->display->display_options['relationships']['tid']['id'] = 'tid';
  $handler->display->display_options['relationships']['tid']['table'] = 'fontyourface_tag_font';
  $handler->display->display_options['relationships']['tid']['field'] = 'tid';
  $handler->display->display_options['relationships']['tid']['required'] = 0;
  /* Field: Font: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'fontyourface_font';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
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
  $handler->display->display_options['fields']['name']['element_type'] = 'h4';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['name']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['name']['link_to_font'] = '0';
  $handler->display->display_options['fields']['name']['display_as'] = '0';
  /* Field: Font: Preview */
  $handler->display->display_options['fields']['preview']['id'] = 'preview';
  $handler->display->display_options['fields']['preview']['table'] = 'fontyourface_font';
  $handler->display->display_options['fields']['preview']['field'] = 'preview';
  $handler->display->display_options['fields']['preview']['label'] = '';
  $handler->display->display_options['fields']['preview']['alter']['alter_text'] = 0;
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
  /* Field: Font: Enable/Disable */
  $handler->display->display_options['fields']['enable_disable_link']['id'] = 'enable_disable_link';
  $handler->display->display_options['fields']['enable_disable_link']['table'] = 'fontyourface_font';
  $handler->display->display_options['fields']['enable_disable_link']['field'] = 'enable_disable_link';
  $handler->display->display_options['fields']['enable_disable_link']['label'] = '';
  $handler->display->display_options['fields']['enable_disable_link']['alter']['alter_text'] = 0;
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
  $handler->display->display_options['fields']['enable_disable_link']['element_type'] = 'div';
  $handler->display->display_options['fields']['enable_disable_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['enable_disable_link']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['enable_disable_link']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['enable_disable_link']['hide_empty'] = 0;
  $handler->display->display_options['fields']['enable_disable_link']['empty_zero'] = 0;
  $handler->display->display_options['fields']['enable_disable_link']['hide_alter_empty'] = 0;
  /* Sort criterion: Font: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'fontyourface_font';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  /* Filter criterion: Font: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'fontyourface_font';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['operator'] = 'contains';
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
  $handler->display->display_options['filters']['tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid']['expose']['operator_id'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['label'] = 'Tags';
  $handler->display->display_options['filters']['tid']['expose']['operator'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['identifier'] = 'tid';
  $handler->display->display_options['filters']['tid']['expose']['required'] = FALSE;
  $handler->display->display_options['filters']['tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  /* Filter criterion: Font: Foundry */
  $handler->display->display_options['filters']['foundry']['id'] = 'foundry';
  $handler->display->display_options['filters']['foundry']['table'] = 'fontyourface_font';
  $handler->display->display_options['filters']['foundry']['field'] = 'foundry';
  $handler->display->display_options['filters']['foundry']['operator'] = 'contains';
  $handler->display->display_options['filters']['foundry']['exposed'] = TRUE;
  $handler->display->display_options['filters']['foundry']['expose']['operator_id'] = 'foundry_op';
  $handler->display->display_options['filters']['foundry']['expose']['label'] = 'Foundry';
  $handler->display->display_options['filters']['foundry']['expose']['operator'] = 'foundry_op';
  $handler->display->display_options['filters']['foundry']['expose']['identifier'] = 'foundry';
  $handler->display->display_options['filters']['foundry']['expose']['required'] = 0;
  $handler->display->display_options['filters']['foundry']['expose']['multiple'] = FALSE;
  /* Filter criterion: Font: License */
  $handler->display->display_options['filters']['license']['id'] = 'license';
  $handler->display->display_options['filters']['license']['table'] = 'fontyourface_font';
  $handler->display->display_options['filters']['license']['field'] = 'license';
  $handler->display->display_options['filters']['license']['operator'] = 'contains';
  $handler->display->display_options['filters']['license']['exposed'] = TRUE;
  $handler->display->display_options['filters']['license']['expose']['operator_id'] = 'license_op';
  $handler->display->display_options['filters']['license']['expose']['label'] = 'License';
  $handler->display->display_options['filters']['license']['expose']['operator'] = 'license_op';
  $handler->display->display_options['filters']['license']['expose']['identifier'] = 'license';
  $handler->display->display_options['filters']['license']['expose']['required'] = 0;
  $handler->display->display_options['filters']['license']['expose']['multiple'] = FALSE;
  /* Filter criterion: Font: Provider */
  $handler->display->display_options['filters']['provider']['id'] = 'provider';
  $handler->display->display_options['filters']['provider']['table'] = 'fontyourface_font';
  $handler->display->display_options['filters']['provider']['field'] = 'provider';
  $handler->display->display_options['filters']['provider']['operator'] = 'contains';
  $handler->display->display_options['filters']['provider']['exposed'] = TRUE;
  $handler->display->display_options['filters']['provider']['expose']['operator_id'] = 'provider_op';
  $handler->display->display_options['filters']['provider']['expose']['label'] = 'Provider';
  $handler->display->display_options['filters']['provider']['expose']['operator'] = 'provider_op';
  $handler->display->display_options['filters']['provider']['expose']['identifier'] = 'provider';
  $handler->display->display_options['filters']['provider']['expose']['required'] = 0;
  $handler->display->display_options['filters']['provider']['expose']['multiple'] = FALSE;
  
  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'admin/appearance/fontyourface/browse';
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
    t('Click a font name to view details and add the font.'),
    t('Font Tag'),
    t('Name'),
    t('Tags'),
    t('Foundry'),
    t('License'),
    t('Provider'),
    t('Page'),
  );

  $views[$view->name] = $view;

  /*
   * View 'fontyourface_enabled'
   */
  $view = new view;
  $view->name = 'fontyourface_enabled';
  $view->description = 'All enabled fonts.';
  $view->tag = '@font-your-face';
  $view->view_php = '';
  $view->base_table = 'fontyourface_font';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'name' => array(
      'label' => 'Name',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_font' => 'edit',
      'display_as' => 'preview',
      'exclude' => 0,
      'id' => 'name',
      'table' => 'fontyourface_font',
      'field' => 'name',
      'relationship' => 'none',
    ),
    'provider' => array(
      'label' => 'Provider',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 0,
      'id' => 'provider',
      'table' => 'fontyourface_font',
      'field' => 'provider',
      'relationship' => 'none',
    ),
    'css_family' => array(
      'label' => 'font-family',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 0,
      'id' => 'css_family',
      'table' => 'fontyourface_font',
      'field' => 'css_family',
      'relationship' => 'none',
    ),
    'tid' => array(
      'label' => 'Tags',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'type' => 'separator',
      'separator' => ', ',
      'exclude' => 0,
      'id' => 'tid',
      'table' => 'fontyourface_tag_font',
      'field' => 'tid',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'name' => array(
      'order' => 'ASC',
      'id' => 'name',
      'table' => 'fontyourface_font',
      'field' => 'name',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', array(
    'enabled' => array(
      'operator' => '=',
      'value' => '1',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'enabled',
      'table' => 'fontyourface_font',
      'field' => 'enabled',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('empty', 'No fonts currently enabled.');
  $handler->override_option('empty_format', '1');
  $handler->override_option('use_ajax', TRUE);
  $handler->override_option('items_per_page', 25);
  $handler->override_option('use_pager', '1');
  $handler->override_option('style_plugin', 'table');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'override' => 1,
    'sticky' => 0,
    'order' => 'asc',
    'columns' => array(
      'name' => 'name',
      'provider' => 'provider',
      'css_family' => 'css_family',
      'tid' => 'tid',
    ),
    'info' => array(
      'name' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'provider' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'css_family' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'tid' => array(
        'separator' => '',
      ),
    ),
    'default' => 'name',
  ));
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->override_option('block_description', '');
  $handler->override_option('block_caching', -1);
  $views[$view->name] = $view;

  return $views;
}
