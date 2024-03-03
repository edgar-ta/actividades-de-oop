
class MiembroDeLaComunidad {};

class Empleado              :   public MiembroDeLaComunidad {};
class Estudiante            :   public MiembroDeLaComunidad {};
class ExAlumno              :   public MiembroDeLaComunidad {};

class Docente               :   public Empleado {};
class Administrativo        :   public Empleado {};

class Administrador         :   public Docente {};
class Maestro               :   public Docente {};

class MaestroAdministrador  :   public Maestro, 
                                public Administrador {};

int main() {
    return 0;
}
