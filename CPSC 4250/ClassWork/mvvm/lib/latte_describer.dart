import 'latte.dart';

/* Special feature of Dart (and some other more recent languages): extensions.
   Extensions let us write methods, getters, and setters on existing classes,
   but we can scope those additional methods to this file (and anything that
   imports this file). This doesn't break encapsulation - we can't access
   anything we couldn't before. Ultimately, extensions are just syntactic
   sugar. I'm writing an extension here so I don't have to dereference a latte
   object a bunch of times in these methods; I can treat the latte as "this".
 */

extension LatteDescriber on Latte {
  String get espressoDescription {
    switch (numEspressoShots) {
      case 1:
        return 'single ';
      case 2:
        return '';
      case 3:
        return 'triple ';
      case 4:
        return 'quad ';
      default:
        return '${numEspressoShots}x ';
    }
  }

  String get description => '${isDecaf ? 'Decaf ' : ''}$espressoDescription$milkType latte';
}