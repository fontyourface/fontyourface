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
            
      if (json.status == 'success') {

        td.find('.enabled-No')
          .addClass('enabled-Yes')
          .removeClass('enabled-No');
        td.find('.fontyourface-indicator').remove();
        link
          .text(Drupal.t('Disable'))
          .addClass('disable-link')
          .removeClass('enable-link')
          .unbind('click')
          .click(fontyourfaceDisableClick);

        $('.view-header p').html(json.enabled);

      } // if
      else {
      
        $('.view-header p').text(Drupal.t('Error. Unable to enable font.'));
      
      } // else

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

      if (json.status == 'success') {

        td.find('.enabled-Yes')
          .addClass('enabled-No')
          .removeClass('enabled-Yes');
        td.find('.fontyourface-indicator').remove();
        link
          .text(Drupal.t('Enable'))
          .addClass('enable-link')
          .removeClass('disable-link')
          .unbind('click')
          .click(fontyourfaceEnableClick);

        $('.view-header p').html(json.enabled);

      } // if
      else {
      
        $('.view-header p').text(Drupal.t('Error. Unable to disable font.'));
      
      } // else

    }, 'json');

    return false;
  
  } // fontyourfaceDisableClick

})(jQuery);
