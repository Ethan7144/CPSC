import 'package:flutter/material.dart';
import 'package:ishmaels/order_view_model.dart';

class ShoppingCart extends StatelessWidget {
  final OrderViewModel orderViewModel;

  const ShoppingCart({super.key, required this.orderViewModel});

  _onDelete(int index) {
    orderViewModel.removeLatte(index);
  }

  @override
  Widget build(BuildContext context) {
    return AnimatedBuilder(
      animation: orderViewModel,
      builder: (context, _) {
        final descriptions = orderViewModel.latteDescriptions;
        return ListView.builder(
          itemCount: orderViewModel.latteCount,
          itemBuilder: (context, index) => Card(
              child: ListTile(
                title: Text(descriptions[index]),
                trailing: ElevatedButton(
                  onPressed: () { _onDelete(index); },
                  child: const Icon(Icons.delete_forever),
                ),
              )
          )
        );
      }
    );
  }
}
