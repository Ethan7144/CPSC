import '../lib/data_structures.dart';
import '../lib/geometry.dart';
// Our project is called "dart_examples" (as defined in pubspec.yaml).
// The import command finds these files in our lib folder.

void main(List<String> arguments) {
  // $i is _string interpolation_
  // $ will look for a variable name after it
  // ${} will run the expression rather than just looking for a variable
  print('Your arguments: $arguments');
  int.tryParse(arguments[0]);
  // try/catch syntax
  try {
    int.parse(arguments[0]);
  } on FormatException catch (ex) {
    print(ex.message);
  }
  print('Hello world: ${rectangleArea(10, 12)}!');
  print('Hello world: ${circleArea(10)}!');

  final students = [
    Person('Ali', 'Nguyen'),
    Person('John', 'Bjorge')
  ];
  // we can just leave out "prepend:" entirely to use the default
  addToList(students, Person('Isabel', 'Ovalles'), prepend: true);

  Map<String, String> nameMapping = {
    'Isabel': 'Ovalles',
    'Ali': 'Nguyen',
    'John': 'Bjorge'
  };

  print(students);
  sortByLastName(students);
  // the List.map() method takes a function, calls that function on each element
  // of the list, then produces an Iterable (list-like thing) of the return values.
  print(students.map((student) =>
    '${student.lastName}, ${student.firstName}'
  ).toList());


}
