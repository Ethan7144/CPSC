
class Latte {
  final int numEspressoShots;
  final String milkType;
  final bool isDecaf;

  const Latte(this.numEspressoShots, this.milkType, this.isDecaf);

  @override
  String toString() {
    return 'Latte{numEspressoShots: $numEspressoShots, milkType: $milkType, isDecaf: $isDecaf}';
  }
}