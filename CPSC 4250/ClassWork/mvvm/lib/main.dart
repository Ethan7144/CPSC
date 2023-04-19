import 'package:flutter/material.dart';
import 'package:ishmaels/latte_order_form.dart';
import 'package:ishmaels/order_view_model.dart';
import 'package:ishmaels/shopping_cart.dart';

import 'latte.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Demo',
      debugShowCheckedModeBanner: false,
      theme: ThemeData(
        primarySwatch: Colors.brown,
      ),
      home: const MyHomePage(title: "Ishmael's"),
    );
  }
}

class MyHomePage extends StatefulWidget {
  const MyHomePage({super.key, required this.title});
  final String title;

  @override
  State<MyHomePage> createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  // we can use any data type for our state variables
  bool _isShowingCart = false;
  // or we can hide our state in other layers of MVVM
  final _orderViewModel = OrderViewModel();

  /* initState() and dispose() are kind of like constructors and destructors
     in C++, but for the State class. While we also have a constructor we can
     implement, it won't have access to all the other objects it may need.
     Instead, we override initState(), which Flutter runs once it's given us
     widget, context, and other useful member variables.
   */
  @override
  initState() {
    // Make sure to call State's initState! Unlike C++ constructors this won't
    // happen automatically.
    super.initState();

    _orderViewModel.addListener(_onLatteAdded);
  }

  @override
  dispose() {
    // Make sure to call State's dispose! Unlike C++ destructors this won't
    // happen automatically.
    super.dispose();

    _orderViewModel.removeListener(_onLatteAdded);
  }

  _onLatteAdded() {
    print('order view model now has ${_orderViewModel.latteCount} lattes');
  }

  _onCartTapped() {
    setState(() {
      _isShowingCart = true;
    });
  }

  _onBackTapped() {
    setState(() {
      _isShowingCart = false;
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        leading: _isShowingCart ? BackButton(
          onPressed: _onBackTapped,
        ) : null,
        title: Text(widget.title),
        centerTitle: true,
        actions: [
          // InkWell is kind of like an extra-lightweight button; its only visual
          // component is a brief highlight animation when tapped
          InkWell(
            onTap: _onCartTapped,
            child: Row(
              children: [
                const Icon(Icons.coffee),
                /* Although this is called AnimatedBuilder, it's really a builder
                   (i.e. something that gets its child via a builder function)
                   that's also a listener. It calls its builder any time the
                   Listenable (animation) notifies its listeners.

                   This is helpful for us in MVVM because it lets our views
                   react to changes published by our view model without our view
                   model having to know _specifically_ which views to tell, and
                   how they should change.
                 */
                AnimatedBuilder(
                  animation: _orderViewModel,
                  builder: (context, _) => Text('${_orderViewModel.latteCount}')
                )
              ],
            )
          ),
          // alternative: wrap the InkWell in a Padding
          const SizedBox(width: 4)
        ]
      ),
      body: Center(
        child: _isShowingCart
            ? ShoppingCart(orderViewModel: _orderViewModel)
            : LatteOrderForm(orderViewModel: _orderViewModel)
      ),
    );
  }
}
