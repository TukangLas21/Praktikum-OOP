// Aria Judhistira / 13523112 / K02

public class Minibus extends Kendaraan {
    private String merk;
    private int tahunKeluaran;

    public Minibus() {
        super();
        this.merk = "XXX";
        this.tahunKeluaran = 0;
    }
    public Minibus(int kendaraanID, String merk, int tahun) {
        super(kendaraanID);
        this.merk = merk;
        this.tahunKeluaran = tahun;
    }
    public Minibus(Minibus minibus) {
        super(minibus);
        this.merk = minibus.merk;
        this.tahunKeluaran = minibus.tahunKeluaran;
    }

    @Override
    public void printInfo() {
        System.out.println("Berikut informasi minibus ini: ");
        System.out.println("ID Kendaraan: " + kendaraanID);
        System.out.println("Merk: " + merk);
        System.out.println("Tahun Keluaran: " + tahunKeluaran);
    }

    @Override
    public int biayaSewa(int lamaSewa) {
        if (lamaSewa <= 5) {
            return 5000000;
        } else {
            return 5000000 + (lamaSewa - 5) * 5000000;
        }
    }

    public int diskon(int lamaSewa) {
        if (lamaSewa > 10) {
            return (int)(biayaSewa(lamaSewa) * 0.1);
        } else {
            return 0;
        }
    }
}
