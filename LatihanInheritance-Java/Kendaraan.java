// Aria Judhistira / 13523112 / K02

abstract public class Kendaraan {

    protected int kendaraanID;

    public Kendaraan() {
        this.kendaraanID = 0;
    }
    public Kendaraan(int kendaraanID) {
        this.kendaraanID = kendaraanID;
    }
    public Kendaraan(Kendaraan kendaraan) {
        this.kendaraanID = kendaraan.kendaraanID;
    }

    abstract public void printInfo();
    abstract public int biayaSewa(int lamaSew);
}
