// Dijkstra's Algorithm in C

#include <stdio.h>
#define INFINITY 9999
#define MAX 10


void Dijkstra(int Graph[MAX][MAX], int n, int start) {
  int cost[MAX][MAX], distance[MAX], pred[MAX];           //zainicjowanie wszystkich potrzebnych zmiennych
  int visited[MAX], count, mindistance, nextnode, i, j;

  //stworzenie macierzy wag
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
 //jezeli wartosc odpowiedniej komórki macierzy jest równa 0 to ustawiamy jej wage na nieskonczonosc
      if (Graph[i][j] == 0)
        cost[i][j] = INFINITY;
 // w przeciwnym razie ustawiamy jej wage zgodnie z podan¹ na krawêdzi np.1,2,10 itd.
      else
        cost[i][j] = Graph[i][j];
//przechodzimy jeszcze raz przez wierzcholki ustawiajac wage od startowego wierzcho³ka jako dystans
  for (i = 0; i < n; i++) {
    distance[i] = cost[start][i];
    pred[i] = start;
    visited[i] = 0;
  }

  distance[start] = 0;
  visited[start] = 1;
  count = 1;
// dopóku mamy do rozpatrzenia jeszcze jakies wierzcholki to...
  while (count < n - 1) {
        //minimalny dystans ustawiamy jako nieskonczonosc
    mindistance = INFINITY;

// przechodzimy po wszystkich wierzcholkach, jezli dystans aktualny jest mniejszy niz poprzedni i wierzcholek nie zostal
    for (i = 0; i < n; i++)  // jeszcze odwiedzony to zastepujemy wartosc nowa mniejsza
      if (distance[i] < mindistance && !visited[i]) {
        mindistance = distance[i];
        nextnode = i;
      }
    // przechodzimy po wezłach których wierzchołki nie zostały odwiedzone i jeżeli...
    visited[nextnode] = 1;
    for (i = 0; i < n; i++)
      if (!visited[i]) // aktualny najmniejszy dystans jest wiekszy niż minimalny dystans plus waga kolejnego wezla to...
        if (mindistance + cost[nextnode][i] < distance[i]) {
          distance[i] = mindistance + cost[nextnode][i];// nastepuje zamiana wartosci na ta mniejsza
          pred[i] = nextnode;
        }
    count++;
  }

  //wyswietlamy dystanse
  for (i = 0; i < n; i++)

  if (i != start) {
      printf("\nDistance from source to %d: %d", i, distance[i]);
    }

}
int main() {
  int Graph[MAX][MAX], i, j, n, u;
  n = 5;
// wczytujemy macierz sasiedztwa
  Graph[0][0] = 0;
  Graph[0][1] = 3;
  Graph[0][2] = 7;
  Graph[0][3] = 1;
  Graph[0][4] = 2;

  Graph[1][0] = 3;
  Graph[1][1] = 0;
  Graph[1][2] = 5;
  Graph[1][3] = 2;
  Graph[1][4] = 2;

  Graph[2][0] = 7;
  Graph[2][1] = 5;
  Graph[2][2] = 0;
  Graph[2][3] = 6;
  Graph[2][4] = 5;

  Graph[3][0] = 1;
  Graph[3][1] = 2;
  Graph[3][2] = 6;
  Graph[3][3] = 0;
  Graph[3][4] = 1;

  Graph[4][0] = 2;
  Graph[4][1] = 2;
  Graph[4][2] = 5;
  Graph[4][3] = 1;
  Graph[4][4] = 2;

    // ustawienie źródła jako wierzchołek numer 0
  u = 0;
  Dijkstra(Graph, n, u);

  return 0;
}
