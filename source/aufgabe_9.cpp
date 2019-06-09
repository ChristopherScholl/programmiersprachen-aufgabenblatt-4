# include <cstdlib>   // std :: rand ()
# include <vector>    // std :: vector <>
# include <list>      // std :: list <>
# include <iostream>  // std :: cout
# include <iterator>  // std :: ostream_iterator <>
# include <algorithm> // std :: reverse , std :: 

int main()
{
  //erstelle einen vector mit der Länge 10
  std::vector <int> v_0(10);
  //iteriere durch alle Elemente des vectors
  for (auto& v : v_0) {
    //füge eine Zufallszahl in das aktuell iterierte Element des vectors ein
    v = std::rand();
  }

  //gib den vector mit Hilfe von ostream_iterator von vorn bis hinten aus
  std::copy(std::cbegin(v_0), std::cend(v_0),
  std::ostream_iterator <int>(std::cout, "\n"));

  //erstelle eine list, die mit den Elementen des vectors gefüllt wird
  std::list <int> l_0(std::cbegin(v_0), std::cend(v_0));
  //erstelle eine zweite list, die mit den Elementen der ersten list gefüllt wird
  std::list <int> l_1(std::cbegin(l_0), std::cend(l_0));
  //kehre die Reihenfolge der Elemente in der zweiten list um
  std::reverse(std::begin(l_1), std::end(l_1));
  //gib die umgekehrte list mit Hilfe von ostream_iterator aus
  std::copy(std::cbegin(l_1), std::cend(l_1),
  std::ostream_iterator <int>(std::cout, "\n"));

  //sortiere die Elemente der zweiten list, mit dem kleinsten Element vorne
  l_1.sort();
  //gib die sortierte list mit Hilfe von ostream_iterator aus
  std::copy(l_1.cbegin(), l_1.cend(),
  std::ostream_iterator <int>(std::cout, "\n"));

  //fülle den vector mit neuen Zufallszahlen
  std::generate(std::begin(v_0), std::end(v_0), std::rand);
  //gib den neu befüllten vector mit Hilfe von ostream_iterator aus
  std::copy(v_0.crbegin(), v_0.crend(),
  std::ostream_iterator <int>(std::cout, "\n"));

  return 0;
}

/*
std::copy(start, end, destination); ist eine Methode, die Elemente aus einer Sequenz in eine andere kopiert.
In diesem Programm kopiert sie die Elemente von Listen und Vektoren in den Ostream-Iterator.
Der Ostream-Iterator ist eine Art Container zum ausgeben von Sequenzen.
Das heißt der copy-Aufruf in den ostream_operator ist quasi eine Ausgabeschleife.
std::generate(start, end, function); ist eine Methode, die alle Elemente eines Containers mit Werten befüllt.
Die Werte werden durch eine vorgegebene Funktion bestimmt. In diesem Fall ist es rand.
Beide Methoden sind quasi effektive auf ein spezielles Feld ausgerichtete Iterations-Schleifen.
*/