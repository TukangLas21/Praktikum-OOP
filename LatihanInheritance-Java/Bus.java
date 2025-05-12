// Aria Judhistira / 13523112 / K02

public class Bus extends Kendaraan {
    private String merk;
    private int tahunKeluaran;
    private int kapasitas;

    public Bus() {
        super();
        this.merk = "XXX";
        this.tahunKeluaran = 0;
        this.kapasitas = 0;
    }
    public Bus(int kendaraanID, String merk, int tahun, int kapasitas) {
        super(kendaraanID);
        this.merk = merk;
        this.tahunKeluaran = tahun;
        this.kapasitas = kapasitas;
    }
    public Bus(Bus bus) {
        super(bus);
        this.merk = bus.merk;
        this.tahunKeluaran = bus.tahunKeluaran;
        this.kapasitas = bus.kapasitas;
    }

    @Override
    public void printInfo() {
        System.out.println("Berikut informasi bus ini: ");
        System.out.println("ID Kendaraan: " + kendaraanID);
        System.out.println("Merk: " + merk);
        System.out.println("Tahun Keluaran: " + tahunKeluaran);
        System.out.println("Kapasitas: " + kapasitas);
    }
    
    @Override
    public int biayaSewa(int lamaSewa) {
        return 1000000 * lamaSewa;
    }
}
