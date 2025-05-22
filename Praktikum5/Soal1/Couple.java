public class Couple<K, V> {

    private K key;
    private V value;

    public Couple(K key, V value) {
        this.key = key;
        this.value = value;
    }

    public K getKey() {
        return key;
    }
    public V getVal() {
        return value;
    }

    public void setKey(K key) {
        this.key = key;
    }
    public void setVal(V value) {
        this.value = value;
    }

    public boolean isEqual(Couple c) {
        return this.key == c.key && this.value == c.value;
    }

    public int nearEQ(Couple couple) {
        if (this.key == couple.key && this.value == couple.value) {
            return 3;
        } else if (this.key == couple.key && this.value != couple.value) {
            return 1;
        } else if (this.key != couple.key && this.value == couple.value) {
            return 2;
        } else return 0;
    }
}