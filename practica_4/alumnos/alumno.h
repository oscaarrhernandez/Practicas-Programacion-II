#define NOTAS 5

typedef struct {
    int dia, mes, anio;
} Fecha;

typedef struct {
    char nombre[81];
    Fecha fnacimiento;
    float notas[NOTAS];
} Alumno;