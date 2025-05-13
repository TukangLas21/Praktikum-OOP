public class Character extends Unit implements Damageable {
    private int score = 0;

    public Character() {
        super("Player1", 100);
        this.score = 0;
    }
    public Character(String name, int health, int score) {
        super(name, health);
        this.score = score;
    }

    public int getScore() {
        return this.score;
    }
    public void setScore(int score) {
        this.score = score;
    }

    @Override
    public void takeDamage(int damage) {
        // if (this.health - damage <= 0) {
        //     System.out.println(this.name + " has been defeated");
        //     this.health = 0;
        // } else {
        //     this.health -= damage;
        // }

        this.health -= damage;
        if (this.health <= 0) {
            System.out.println(this.name + " has been defeated");
        }
    }

    public void increaseScore(int points) {
        this.score += points;
    }

    @Override
    public String toString() {
        String s = this.name + " [Health: " + this.health + ", Score: " + this.score + "]";
        return s;
    }
}