import 'package:flutter/cupertino.dart';
import 'event.dart';

class AddEventPage extends StatefulWidget {
  final Function(Event)? onAddEvent;

  AddEventPage({this.onAddEvent});

  @override
  _AddEventPageState createState() => _AddEventPageState();
}

class _AddEventPageState extends State<AddEventPage> {
  final GlobalKey<FormState> _formKey = GlobalKey<FormState>();
  late String _title;
  late String _description;
  late DateTime _startDate;
  late DateTime _endDate;

  @override
  void initState() {
    super.initState();
    _startDate = DateTime.now();
    _endDate = DateTime.now();
  }

  void _submitForm() {
    if (!_formKey.currentState!.validate()) {
      return;
    }

    _formKey.currentState!.save();

    if (_endDate.isBefore(_startDate)) {
      return;
    }

    Event newEvent = Event(
      title: _title,
      description: _description,
      startDate: _startDate,
      endDate: _endDate,
    );
    if (widget.onAddEvent != null) {
      widget.onAddEvent!(newEvent);
    }

    Navigator.of(context).pop();
  }

  void _showError(String message) {
    showCupertinoDialog(
      context: context,
      builder: (BuildContext context) => CupertinoAlertDialog(
        title: const Text('Error'),
        content: Text(message),
        actions: <Widget>[
          CupertinoDialogAction(
            child: const Text('OK'),
            onPressed: () => Navigator.of(context).pop(),
          ),
        ],
      ),
    );
  }

  @override
  Widget build(BuildContext context) {
    return CupertinoPageScaffold(
      navigationBar: const CupertinoNavigationBar(
        middle: Text('Add Event'),
      ),
      child: SafeArea(
        child: Form(
          key: _formKey,
          child: ListView(
            padding: const EdgeInsets.all(16.0),
            children: <Widget>[
              CupertinoTextField(
                placeholder: 'Title',
                decoration: const BoxDecoration(
                    border: Border(
                        bottom: BorderSide(
                            width: 0.0, color: CupertinoColors.inactiveGray))),
                onSubmitted: (String? value) {
                  if (value == null || value.isEmpty) {
                    _showError("Please enter a title");
                  } else {
                    _title = value;
                  }
                },
              ),
              const SizedBox(height: 16.0),
              CupertinoTextField(
                placeholder: 'Description',
                decoration: const BoxDecoration(
                    border: Border(
                        bottom: BorderSide(
                            width: 0.0, color: CupertinoColors.inactiveGray))),
                onSubmitted: (String? value) {
                  if (value == null || value.isEmpty) {
                    _showError("Please enter a description");
                  } else {
                    _description = value;
                  }
                },
              ),
              const SizedBox(height: 16.0),
              const Text('Start Date/Time'),
              const SizedBox(height: 8.0),
              CupertinoDatePicker(
                initialDateTime: _startDate,
                onDateTimeChanged: (DateTime newDate) {
                  setState(() {
                    _startDate = newDate;
                  });
                },
                use24hFormat: true,
                mode: CupertinoDatePickerMode.dateAndTime,
              ),
              const SizedBox(height: 16.0),
              const Text('End Date/Time'),
              const SizedBox(height: 8.0),
              CupertinoDatePicker(
                initialDateTime: _endDate,
                onDateTimeChanged: (DateTime newDate) {
                  setState(() {
                    _endDate = newDate;
                  });
                },
                use24hFormat: true,
                mode: CupertinoDatePickerMode.dateAndTime,
              ),
              const SizedBox(height: 32.0),
              CupertinoButton.filled(
                onPressed: _submitForm,
                child: const Text('Add Event'),
              ),
            ],
          ),
        ),
      ),
    );
  }
}
