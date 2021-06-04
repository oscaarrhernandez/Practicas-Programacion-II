/*
 * Genera un Array aleatorio.
 */
void CargarArrayClaseAleatorio (Alumno *cla, int n);

/*
 * Calcula la nota final de cada alumno del Array generado.
 */
float NotaFinalAlumno (const Alumno *alul);

/*
 * Muestra el array de la clase: Nombres, F.Nacim, Notas y Final.
 */
void MostrarArrayClase (const Alumno *cla, int n);

/*
 * Calcula la nota media del Array generado.
 */
float NotaMediaArrayClase (const Alumno *cla, int n);

/*
 * Calcula la menor nota de todo el Array generado.
 */
Alumno MenorNotaArrayClase (const Alumno *cla, int n, Alumno *alu);

/*
 * Calcula la persona con más edad en el Array generado.
 */
void MayorEdadArrayClase (const Alumno *cla, int n, Alumno *alu);