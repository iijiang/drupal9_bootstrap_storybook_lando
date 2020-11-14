# Usage examples

```
# Doing a drush site install
lando drush si --db-url=mysql://drupal9:drupal9@database/drupal9 -y

drupal9@database/drupal9 -y

# Run composer tests
lando composer test

# Drop into a mysql shell
lando mysql

# Check hte app's installed php extensions
lando php -m
```