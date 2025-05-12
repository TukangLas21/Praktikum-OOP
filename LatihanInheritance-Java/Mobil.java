// Aria Judhistira / 13523112 / K02

public class Mobil extends Kendaraan {
    private String merk;
    private int tahunKeluaran;
    private String namaSupir;

    public Mobil() {
        super();
        this.merk = "XXX";
        this.tahunKeluaran = 0;
        this.namaSupir = "XXX";
    }

    public Mobil(int kendaraanID, String merk, int tahun, String nama) {
        super(kendaraanID);
        this.merk = merk;
        this.tahunKeluaran = tahun;
        this.namaSupir = nama;
    }

    public Mobil(Mobil mobil) {
        super(mobil);
        this.merk = mobil.merk;
        this.tahunKeluaran = mobil.tahunKeluaran;
        this.namaSupir = mobil.namaSupir;
    }

    @Override
    public void printInfo() {
        System.out.println("Berikut informasi mobil ini: ");
        System.out.println("ID Kendaraan: " + kendaraanID);
        System.out.println("Merk: " + merk);
        System.out.println("Tahun Keluaran: " + tahunKeluaran);
        System.out.println("Nama Supir: " + namaSupir);
    }

    @Override
    public int biayaSewa(int lamaSewa) {
        return 500000 * lamaSewa;
    }
    
}
