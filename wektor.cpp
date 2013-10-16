#include <cstdio>
#include <cmath>

using namespace std;

bool CzyRowneLiczby(float a, float b)
{
	return fabs(a-b) < 0.001f;
}

class Wektor
{
	float * xy; // domyslnie prywatne

public:
	Wektor()
	{
		// konstruktor bezargumentowy
		xy = new float[2];
		//xy[0] = 0; xy[1] = 0;
		UstawX(0); UstawY(0);
	}

	Wektor(float x, float y)
	{
		// konstruktor dwuargumentowy
		xy = new float[2];
		// xy[0] = x; xy[1] = y;
		UstawX(x); UstawY(y);
	}

	~Wektor()
	{
		// destruktor
		delete[] xy;
	}

	float X() const { return xy[0]; }
	float Y() const { return xy[1]; }

	void UstawX(float x) { xy[0] = x; }
	void UstawY(float y) { xy[1] = y; }

	float Dlugosc()
	{
		return sqrtf(X() * X() + Y() * Y());
	}

	Wektor operator * (float s)
	{
		// mnozymy ten wektor przez liczbe s
		Wektor wynik;
		wynik.UstawX(X() * s);
		wynik.UstawY(Y() * s);
		return wynik;
	}

	Wektor operator + (Wektor & drugiWektor)
	{
		// dodajemy drugi wektor do tego
		Wektor wynik;
		wynik.UstawX(X() + drugiWektor.X());
		wynik.UstawY(Y() + drugiWektor.Y());
		return wynik;
	}

	bool operator == (Wektor & drugiWektor)
	{
		// porownujemy ten wektor z drugim
		return CzyRowneLiczby(X(), drugiWektor.X()) && CzyRowneLiczby(Y(), drugiWektor.Y());
	}

	bool operator != (Wektor & drugiWektor)
	{
		//return !(operator == (drugiWektor));
		// wyluskanie tego wektora, porownanie go z drugim, negacja wyniku
		return !(*this == drugiWektor);
	}

	Wektor (const Wektor& wektor)
	{
        xy = new float[2];
        UstawX(wektor.X());
        UstawY(wektor.Y());
	}
};

int main()
{
	Wektor zerowy;
	Wektor dwojki(2.0f, 2.0f);
	printf("dlugosc dwojki: %.4f\n", dwojki.Dlugosc());
	printf("dlugosc zera: %.4f\n", zerowy.Dlugosc());
	printf("czy wektory: zero i dwojki sa rowne: %s\n", (zerowy == dwojki ? "tak" : "nie"));

	Wektor prawieDwojki(2.00001f, 2.00001f);
	printf("czy wektory: dwojki i prawieDwojki sa rowne: %s\n", (dwojki == prawieDwojki ? "tak" : "nie"));

	// nastepne zajecia: referencje i przetestowanie operatorow +, *
	return 0;
}
