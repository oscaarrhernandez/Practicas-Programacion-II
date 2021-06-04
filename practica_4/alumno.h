#define NOTAS 5

typedef struct Fecha{
	int dia;
	int mes;
	int anio;
} Fecha;

typedef struct {
	char nombre [20];
	char apellidos [61];
	Fecha fnacimiento;
	float notas[NOTAS];
} Alumno;

typedef struct {
	Alumno clase[15];
} Clase;
