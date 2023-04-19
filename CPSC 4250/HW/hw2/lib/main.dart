import 'package:flutter/cupertino.dart';
import 'events/displayEvent.dart';
import 'events/addevent.dart';
void main() {
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return CupertinoApp(
      title: 'My App',
      home: CupertinoTabScaffold(
        tabBar: CupertinoTabBar(
          items: const [
            BottomNavigationBarItem(
              icon: Icon(CupertinoIcons.calendar),
              label: 'Events',
            ),
            BottomNavigationBarItem(
              icon: Icon(CupertinoIcons.add),
              label: 'Add Event',
            ),
          ],
        ),
        tabBuilder: (BuildContext context, int index) {
          if (index == 0) {
            return CupertinoPageScaffold(
              child: MyEventsPage(),
            );
          } else {
            return CupertinoPageScaffold(
              child: AddEventPage(onAddEvent: (Event ) {  },),
            );
          }
        },
      ),
    );
  }
}
