import 'package:flutter/cupertino.dart';
import 'package:intl/intl.dart';
import 'event.dart';

class MyEventsPage extends StatefulWidget {
  @override
  _MyEventsPageState createState() => _MyEventsPageState();
}

class _MyEventsPageState extends State<MyEventsPage> {
  List<Event> events = [
    Event(
      title: 'Event 1',
      description: 'This is the first event',
      startDate: DateTime(2023, 4, 18, 10, 0),
      endDate: DateTime(2023, 4, 18, 12, 0),
    ),
    Event(
      title: 'Event 2',
      description: 'This is the second event',
      startDate: DateTime(2023, 4, 19, 14, 0),
      endDate: DateTime(2023, 4, 19, 16, 0),
    ),
  ];

  @override
  Widget build(BuildContext context) {
    return CupertinoPageScaffold(
      navigationBar: const CupertinoNavigationBar(
        middle: Text('My Events'),
      ),
      child: SafeArea(
        child: ListView.builder(
          itemCount: events.length,
          itemBuilder: (BuildContext context, int index) {
            return CupertinoButton(
              onPressed: () {
                
              },
              child: Column(
                crossAxisAlignment: CrossAxisAlignment.center,
                children: <Widget>[
                  Text(
                    events[index].title,
                    style: const TextStyle(
                      fontWeight: FontWeight.bold,
                      fontSize: 16,
                    ),
                  ),
                  const SizedBox(height: 4),
                  Text(
                    '${DateFormat.yMMMd().add_jm().format(events[index].startDate)} - ${DateFormat.yMMMd().add_jm().format(events[index].endDate)}',
                    style: const TextStyle(
                      color: CupertinoColors.secondaryLabel,
                      fontSize: 12,
                    ),
                  ),
                  const SizedBox(height: 4),
                  Text(
                    events[index].description,
                    style: const TextStyle(
                      color: CupertinoColors.secondaryLabel,
                      fontSize: 12,
                    ),
                  ),
                ],
              ),
            );
          },
        ),
      ),
    );
  }
}
