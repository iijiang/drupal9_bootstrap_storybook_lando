import {
  configure
} from '@storybook/html';

import '../src/sass/main.style.scss';
import jquery from 'jquery';
global.$ = jquery;
global.jQuery = jquery;

import './_drupal.js';

import Twig from 'twig';
import twigDrupal from 'twig-drupal-filters';
// Add the filters to Twig instance.
twigDrupal(Twig);

configure(require.context('../src/components', true, /\.stories\.js$/), module);
