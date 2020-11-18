'use strict';

import './polyfill'

(function ($) {
  // Responsive check helper:
  // USAGE: if (Drupal.device.isMobile()) {}
  Drupal.device = {
    isDesktop: function () {
      return ($(window).innerWidth() > 980);
    },
    isTablet: function () {
      return ($(window).innerWidth() <= 980 && $(window).innerWidth() > 728);
    },
    isMobile: function () {
      return ($(window).innerWidth() <= 728);
    }
  };

})(jQuery, Drupal);
