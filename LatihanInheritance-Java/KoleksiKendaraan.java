// Aria Judhistira / 13523112 / K02

public class KoleksiKendaraan {
    private Kendaraan[] kendaraan;
    private int Neff;
    private int size;

    public KoleksiKendaraan() {
        this.size = 100;
        this.kendaraan = new Kendaraan[size];
        this.Neff = 0;
    }
    public KoleksiKendaraan(int size) {
        this.size = size;
        this.kendaraan = new Kendaraan[size];
        this.Neff = 0;
    }
    public KoleksiKendaraan(KoleksiKendaraan koleksi) {
        this.size = koleksi.size;
        this.kendaraan = new Kendaraan[size];
        this.Neff = koleksi.Neff;
        for (int i = 0; i < Neff; i++) {
            this.kendaraan[i] = koleksi.kendaraan[i];
        }
    }

    public void printAll() {
        System.out.println("Berikut adalah daftar kendaraan yang ada: ");
        for (int i = 0; i < Neff; i++) {
            kendaraan[i].printInfo();
            System.out.println();
        }
    }
}
