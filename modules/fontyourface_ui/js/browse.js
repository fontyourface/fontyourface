(function ($) {

  Drupal.behaviors.fontyourfaceBrowse = {

    attach:function(context, settings) {

      $('.fontyourface-footer a.enable-link').click(fontyourfaceEnableClick);
      $('.fontyourface-footer a.disable-link').click(fontyourfaceDisableClick);

    } // attach

  } // Drupal.behaviors.fontyourfaceAddForm

  function fontyourfaceEnableClick() {
  
    var link = $(this);
    var fid = link.parent().attr('data-fid');
    var enableUrl = Drupal.settings.basePath + 'admin/appearance/fontyourface/ajax/enable/' + fid;

    $('<span class="fontyourface-indicator"></span>').appendTo(this);

    $.post(enableUrl, {fid: fid}, function(json) {

      var td = link.parents('td');
            
      if (json.complete == '1') {

        td.find('.enabled-No')
          .addClass('enabled-Yes')
          .removeClass('enabled-No');
        link
          .text(Drupal.t('Disable'))
          .addClass('disable-link')
          .removeClass('enable-link')
          .unbind('click')
          .click(fontyourfaceDisableClick);

      } // if

      td.find('.fontyourface-indicator').remove();
      $('.view-header').html(json.status);

    }, 'json');

    return false;
  
  } // fontyourfaceEnableClick
  
  function fontyourfaceDisableClick() {
  
    var link = $(this);
    var fid = link.parent().attr('data-fid');
    var disableUrl = Drupal.settings.basePath + 'admin/appearance/fontyourface/ajax/disable/';

    $('<span class="fontyourface-indicator"></span>').appendTo(this);
    
    $.post(disableUrl, {fid: fid}, function(json) {

      var td = link.parents('td');

      if (json.complete == '1') {

        td.find('.enabled-Yes')
          .addClass('enabled-No')
          .removeClass('enabled-Yes');
        link
          .text(Drupal.t('Enable'))
          .addClass('enable-link')
          .removeClass('disable-link')
          .unbind('click')
          .click(fontyourfaceEnableClick);

      } // if
      
      td.find('.fontyourface-indicator').remove();
      $('.view-header').html(json.status);

    }, 'json');

    return false;
  
  } // fontyourfaceDisableClick

})(jQuery);
