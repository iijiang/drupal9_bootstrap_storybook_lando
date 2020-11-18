(function ($, Drupal) {
  $('.navbar-toggle', context).on('click', function (e) {
    $(this).toggleClass('collapsed active navbar-toggle--inactive');
    $('body').toggleClass('nav--collapsed');
    $($(this).data("target")).toggleClass("show");
  });
}(jQuery, Drupal));
