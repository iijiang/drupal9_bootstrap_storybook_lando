# Installation

bootstrap_storybook theme uses [Webpack](https://webpack.js.org) to compile and bundle SASS and JS.
It is a component-first designed theme, so each component is available for Drupal and Storybook

#### Step 1
Make sure you have Node and npm installed.
You can read a guide on how to install node here: https://docs.npmjs.com/getting-started/installing-node

If you prefer to use [Yarn](https://yarnpkg.com) instead of npm, install Yarn by following the guide [here](https://yarnpkg.com/docs/install).

#### Step 2
Go to the root of bootstrap_storybook theme and run the following commands: `npm install` or preferrably `yarn install`.

#### Step 3
Update `proxy` in **config/config.json**.

#### Step 4
Run the following command to compile Sass and watch for changes: `npm run watch` or `yarn watch`.

#### Step 5
Make sure that you have the `components` module downloaded and enabled: `composer require drupal/components` and then enable the module: `drush en components -y`

# Updating the subtheme
In some scenarios you might like to update your subtheme with a new release of bootstrap_storybook, for those cases you may follow the steps below:

- Update the parent theme: `composer update drupal/bootstrap_storybook`
- Make sure the bootstrap_storybook is enabled: `drush en bootstrap_storybook`
- Set default theme to something else so we can temporarily uninstall it and move it
```
drush config-set system.theme default bartik
drush theme:uninstall SUBTHEMENAME
mv web/themes/custom/SUBTHEMENAME ../SUBTHEMENAME.bak
drush --include="web/themes/contrib/bootstrap_storybook" bootstrap_storybook:create "My Bootstrap Storybook Theme"
```
- Have a look at the differences, and make adjustments as necessary
`git diff -- . ':(exclude)web/themes/custom/my_bootstrap_storybook/package-lock.json'`
- Make sure things run smoothly
```
npm install
drush theme:enable SUBTHEMENAME
drush config-set system.theme default SUBTHEMENAME
yarn crazy
```
