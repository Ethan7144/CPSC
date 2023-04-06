import "dart:core";

class Timer {
  DateTime? _startTime;
  DateTime? _stopTime;
  bool _isRunning = false;

  void start() {
    if (_isRunning) {
      return;
    }
    _startTime = DateTime.now();
    _isRunning = true;
  }

  void stop() {
    if (!_isRunning) {
      return;
    }
    _stopTime = DateTime.now();
    _isRunning = false;
  }

  void reset() {
    _startTime = null; // resets to null
    _stopTime = null; // resets to null
    _isRunning = false; // resets status to off
  }

  int? get duration { // gets the duration by subtracting the end time by the start time
    if (_startTime != null && _stopTime != null) {
      return _stopTime!.difference(_startTime!).inMilliseconds;
    }
    return null;
  }


  DateTime? get startTime => _startTime; // getters
  DateTime? get stopTime => _stopTime; // getters
  bool get isRunning => _isRunning; // getters

  String get displayString { // this is how it displays everything, run print(timer.displayString) in order to see all info about the run
    final duration = this.duration;
    if (_startTime != null && _stopTime != null && duration != null) {
      final startTimeString = _startTime!.toLocal().toString();
      final stopTimeString = _stopTime!.toLocal().toString();
      return 'Start Time: $startTimeString\nStop Time: $stopTimeString\nDuration: $duration ms';
    }
    return 'Timer has not started or stopped';
  }
}