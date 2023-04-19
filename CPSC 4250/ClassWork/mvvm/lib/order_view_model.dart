import 'package:flutter/widgets.dart';

import 'latte.dart';
import 'latte_describer.dart';

/* View models in Flutter typically involve subclassing ChangeNotifier.
   The main goal of using MVVM over alternatives is so that each layer only
   has to care about the interface of the next layer down. In this case, the
   views know that our view model offers addLatte, removeLatte, latteCount, and
   latteDescriptions, and our view model knows that our model (the list) offers
   add and removeAt, but our list doesn't know about our view model and our
   view model doesn't know any specifics about our views. It just knows that
   at some point some other code will register listeners through the methods
   inherited from ChangeNotifiers, and it should use notifyListeners to notify
   those listeners when changes occur. It's on the views to register themselves
   and to determine what to do when changes occur, keeping our view model focused
   on its responsibilities.
 */
class OrderViewModel extends ChangeNotifier {
  final List<Latte> _lattes = [];

  void addLatte(Latte latte) {
    print('adding $latte to $_lattes');
    _lattes.add(latte);
    // call this after making any modifications to the model
    notifyListeners();
  }

  void removeLatte(int index) {
    _lattes.removeAt(index);
    notifyListeners();
  }

  // don't notify listeners for a read-only action; that would cause infinite recursion
  int get latteCount => _lattes.length;

  /* We could just return the list itself, but part of MVVM is limiting the interface
     of our view model to just what the view needs, no more than that. It's always
     easier to open up more access than it is to restrict or change access.
   */
  List<String> get latteDescriptions => _lattes.map(
    (latte) => latte.description
  ).toList();
}