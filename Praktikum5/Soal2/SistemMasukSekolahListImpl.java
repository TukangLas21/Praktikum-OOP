import java.util.LinkedList;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.stream.Collectors;

/**
 * Implementasi dari interface SistemMasukSekolahList menggunakan LinkedList
 * PETUNJUK:
 * - Gunakan LinkedList sebagai struktur data utama
 * - Manfaatkan fitur Java Collections
 */
public class SistemMasukSekolahListImpl implements SistemMasukSekolahList {
    
    // Atribut: gunakan LinkedList<Student> untuk menyimpan data siswa
    private LinkedList<Student> students;
    
    /**
     * Constructor: inisialisasi LinkedList students
     */
    public SistemMasukSekolahListImpl() {
        this.students = new LinkedList<>();
    }
    
    @Override
    public void addStudent(Student student) {
        // Menambahkan siswa ke dalam list
        students.add(student);
    }
    
    @Override
    public void addFirstStudent(Student student) {
        // Menambahkan siswa di awal list
        this.students.addFirst(student);
    }
    
    @Override
    public void addLastStudent(Student student) {
        // Menambahkan siswa di akhir list
        this.students.addLast(student);
    }
    
    @Override
    public Student getFirstStudent() {
        // Mengambil siswa pertama di list
        Student student = students.peekFirst();
        if (student != null) return student;
        return null;
    }
    
    @Override
    public Student getLastStudent() {
        // Mengambil siswa terakhir di list
        Student student = students.peekLast();
        if (student != null) return student;
        return null;
    }
    
    @Override
    public Student removeFirstStudent() {
        // Menghapus dan mengembalikan siswa pertama di list
        Student student = students.removeFirst();
        if (student != null) return student;
        return null;
    }
    
    @Override
    public Student removeLastStudent() {
        // Menghapus dan mengembalikan siswa terakhir di list
        Student student = students.removeLast();
        if (student != null) return student;
        return null;
    }
    
    @Override
    public int removeStudentsByGpa(double minGpa) {
        // Menghapus siswa dengan GPA < minGpa
        // Return jumlah siswa yang dihapus
        int count = 0;

        Iterator<Student> it = students.iterator();
        // Student st = students.peekFirst();
        // if (st.getGpa() < minGpa) {
        //     students.removeFirst();
        // }

        if (it.hasNext()) {
            do {
                Student student = it.next();
                if (student.getGpa() < minGpa) {
                    it.remove();
                    count++;
                }
            } while (it.hasNext());

        }
        return count;
    }
    
    @Override
    public List<Student> getStudentsWithHighGpa(double minGpa) {
        // Mencari siswa dengan GPA >= minGpa
        List<Student> list = new ArrayList<>();
        Iterator<Student> it = students.iterator();
        // Student st = students.peekFirst();
        // if (st.getGpa() >= minGpa) {
        //     list.add(st);
        // }
        if (it.hasNext()) {
            do {
                Student student = it.next();
                if (student.getGpa() >= minGpa && !list.contains(student)) {
                    list.add(student);
                }
            } while (it.hasNext());
        }
        return list;
    }
    
    @Override
    public List<Student> getStudentsByAge(int age) {
        // Mencari siswa dengan umur tertentu
        List<Student> list = new ArrayList<>();
        Iterator<Student> it = students.iterator();
        // Student st = students.peekFirst();
        // if (st.getAge() == age) {
        //     list.add(st);
        // }
        if (it.hasNext()) {
            do {
                Student student = it.next();
                if (student.getAge() == age && !list.contains(student)) {
                    list.add(student);
                }
            } while (it.hasNext());

        }
        return list;
    }
    
    @Override
    public List<String> getYoungHighAchieverNames(int maxAge, double minGpa) {
        // Mencari nama siswa muda (umur < maxAge) dan berprestasi (GPA >= minGpa)
        List<String> list = new ArrayList<>();
        Iterator<Student> it = students.iterator();
        // Student st = students.peekFirst();
        // if (st.getGpa() >= minGpa && st.getAge() < maxAge) {
        //     list.add(st.getName());
        // }
        if (it.hasNext()) {
            do {
                Student student = it.next();
                if (student.getGpa() >= minGpa && student.getAge() < maxAge && !list.contains(student)) {
                    list.add(student.getName());
                }
            } while (it.hasNext());
        }

        return list;
    }
    
    @Override
    public List<Student> getAllStudents() {
        // Mengembalikan seluruh siswa dalam list
        return students;
    }
}
