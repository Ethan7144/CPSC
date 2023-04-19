import 'package:flutter/material.dart';
import 'package:ishmaels/order_view_model.dart';
import 'latte.dart';

/* This file contains a StatefulWidget subclass, a State subclass, and data
   that goes with them. You'll pretty much always find these in pairs, with
   the widget being public and the state private.
 */

const _milkOptions = [
  '2%',
  'Skim',
  'Soy',
  'Almond',
  'Oat'
];

const _sizeOptions = [
  'Casual',
  'Standard',
  'Monday',
  'Sheesh'
];

// StatefulWidget does very little - it accepts constructor parameters and
// creates instances of our State class. Think of t-rex arms.
class LatteOrderForm extends StatefulWidget {
  final OrderViewModel orderViewModel;
  const LatteOrderForm({super.key, required this.orderViewModel});

  @override
  State<LatteOrderForm> createState() => _LatteOrderFormState();
}

// see https://docs.flutter.dev/cookbook/forms/validation for another example of forms with validation

// State does all the heavy lifting here - it keeps track of our variables and
// implements the build() method.
class _LatteOrderFormState extends State<LatteOrderForm> {
  /* A GlobalKey helps uniquely identify a widget, but it also gives us access
     to the form's methods, such as validate(). IMO it's kind of a hack since
     we're not really supposed to have direct references between States, but
     that's how the Flutter team implemented it.
   */
  final _formKey = GlobalKey<FormState>();
  /* We'll often rely on other classes to help manage our state for us.
     Next week's class on MVVM will be all about patterns for implementing
     those classes ourselves, but here we have a simple example of using
     a TextEditingController to manage the state of the customer's name
     and number of espresso shots. By providing these controllers to their
     respective TextFormFields, we register them to receive updates on the
     contents of those TextFormFields whenever the user types something.
     Later, we can use the controllers' public getter .text to access the
     latest value. TextEditingController also provides other methods such
     as .reset() to set the field back to its initial value, as well as
     direct access to what portion of the text field is selected.
   */
  final _nameController = TextEditingController(text: null);
  final _numEspressoShotsController = TextEditingController(text: '2');
  // We don't have controllers for all form fields, so we keep track of
  // dropdown and toggle values directly ourselves.
  String _milkType = '2%';
  String _size = _sizeOptions[1];
  bool _isDecaf = false;

  /* build() methods tend to get complicated with all the nested widgets.
     I recommend getting into the habit of writing private methods for any
     callbacks such as validation or input handlers by default so you don't
     lose track of callback code in the middle of widget tree building code.
   */
  String? _validateName(String? name) {
    if(name == null || name.isEmpty) {
      return 'Please fill in a name.';
    }
    return null;
  }

  _onMilkTypeChanged(String? milkType) {
    if(milkType != null) {
      setState(() {
        _milkType = milkType;
      });
    }
  }

  _onSizeChanged(String? size) {
    if(size != null) {
      setState(() {
        _size = size;
      });
    }
  }

  _onIsDecafChanged(bool isDecaf) {
    setState(() {
      _isDecaf = isDecaf;
    });
  }

  _submit() {
    /* _formKey has a pointer to our Form's utility methods like .validate()
       and .reset().
     */
    if(_formKey.currentState!.validate()) {
      final latte = Latte(
        int.parse(_numEspressoShotsController.text),
        _milkType,
        _isDecaf
      );
      // Every StatefulWidget object has a corresponding State object and vice
      // versa. You can access the widget via a member variable inherited from State.
      widget.orderViewModel.addLatte(latte);
      // note: this only resets some of the fields; the dropdowns don't handle initial values properly
      _formKey.currentState!.reset();
    }
  }

  @override
  Widget build(BuildContext context) {
    print('milk type: $_milkType, size: $_size');
    // Form gives us a way to validate all inputs at once (see _submit())
    return Form(
      key: _formKey,
      child: Column(
        children: [
          TextFormField(
            decoration: const InputDecoration(labelText: 'Name'),
            controller: _nameController,
            // validator is a function that returns an error message if the input
            // is invalid, null if there's no problems with it
            validator: _validateName,
          ),
          TextFormField(
            decoration: const InputDecoration(labelText: 'Espresso shots'),
            controller: _numEspressoShotsController,
            keyboardType: TextInputType.number,
          ),
          DropdownButtonFormField(
            /* Writing all of the DropdownMenuItems by hand is tedious and will
               likely involve a lot of error-prone copy/pasting. A more elegant
               way to make a list of dropdown items is to take a List of data
               and use List.map() to transform the data into menu items.
             */
            items: _milkOptions.map((String option) => DropdownMenuItem(
              value: option,
              child: Text(option)
            )).toList(), // .toList() since .map() returns an Iterable for some reason
            value: _milkType, // you must specify a value or else Flutter throws an exception due to not know what's selected
            onChanged: _onMilkTypeChanged,
          ),
          DropdownButtonFormField(
              items: _sizeOptions.map((String option) => DropdownMenuItem(
                  value: option,
                  child: Text(option)
              )).toList(),
              value: _size,
              onChanged: _onSizeChanged
          ),
          SwitchListTile(
            value: _isDecaf,
            title: const Text('Decaf?'),
            onChanged: _onIsDecafChanged
          ),
          ElevatedButton(
            onPressed: _submit,
            child: const Text('Add to cart')
          )
        ],
      )
    );
  }
}
