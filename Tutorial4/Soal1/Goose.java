class Goose {
    private String name;
    private int honk;

    public Goose() {
        this.name = "Horrible";
        this.honk = 1;
    }

    public Goose(String name, int honk) {
        this.name = name;
        this.honk = honk;
    }

    public void steal(String thing) {
        System.out.println(this.name + " steals " + thing);       
    }

    public String toString() {
        String s = this.name + " goose says";
        for (int i = 0; i < this.honk; i++) {
            s += " honk";
        }
        return s;
    }

    // public static void main(String args[]) {
    //     Goose g = new Goose();
    //     Goose h = new Goose("Sung Jin-woo", 3);
    //     System.out.println(g);
    //     System.out.println(h);
    //     h.steal("dagger");
    // }

    /*
    Pada soal ini anda diminta untuk membuat sebuah kelas Goose, yaitu kelas yang merepresentasikan angsa dari sebuah game bernama “Solo Goose”. Berikut adalah spesifikasi dari kelas Goose:
    Memiliki atribut name (String), dan honk (int).
    Memiliki dua buah konstruktor, yaitu Goose() dan Goose(String name, int honk). Objek Goose defaultnya memiliki name “Horrible” dan nilai honk = 1
    Memiliki method void steal(String thing) dengan thing adalah nama benda yang dicuri objek Goose.
    Memiliki method String toString() yang akan mencetak nama dan “honk” sebanyak honk yang dimiliki objek tersebut
    */
}