export default {
  title: 'Buttons'
};

import { useEffect } from '@storybook/client-api';
import button from './button.twig';
import drupalAttribute from 'drupal-attribute';
import './button.scss';
import './button.js';

export const button_primary = () => {
  useEffect(() => Drupal.attachBehaviors(), []);
  return button({
    attributes: new drupalAttribute(),
    plugin_id: "button_primary",
    type: "primary",
    value: "Primary Button"
  })
};

export const button_secondary = () => {
  useEffect(() => Drupal.attachBehaviors(), []);
  return button({
    attributes: new drupalAttribute(),
    plugin_id: "button_secondary",
    type: "secondary",
    value: "Secondary Button"
  })
};