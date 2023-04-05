
void addToList<T>(
  List<T> list,
  T addition,
  // optional _named_ parameter - specified as "prepend:"
  { bool prepend = false }
) {
  if(prepend) {
    list.insert(0, addition);
  } else {
    list.add(addition);
  }
}

void sortList(List<String> list) {
  list.sort();
}

class Person {
  final String firstName;
  final String lastName;

  Person(this.firstName, this.lastName);

  @override
  String toString() {
    return '$firstName $lastName';
  }
}

void sortByLastName(List<Person> peeps) {
  peeps.sort((Person a, Person b) =>
    a.lastName.compareTo(b.lastName)
  );
}