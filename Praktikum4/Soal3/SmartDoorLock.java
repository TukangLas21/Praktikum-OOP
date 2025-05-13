public class SmartDoorLock extends SecurityDevice implements EnergyMonitored {
    private int batteryLevel;      // Level baterai (0-100)
    private boolean doorOpen;      // Status pintu (terbuka/tertutup)
    private static final int MAX_BATTERY = 100;
    

    public SmartDoorLock(String name, String password) {
        super (name, password);
        this.batteryLevel = MAX_BATTERY;
        this.doorOpen = false; 
    }

    public double getEnergyConsumption() {
        if (this.isActive()) {
            return 2.5; 
        } else {
            return 0.5; 
        }
    }
    
    public int getEnergyEfficiencyRating() {
        if (batteryLevel <= 20) {
            return 1; 
        } else if (batteryLevel <= 40) {
            return 2; 
        } else if (batteryLevel <= 60) {
            return 3; 
        } else if (batteryLevel <= 80) {
            return 4; 
        } else {
            return 5; 
        }
    }
    
    public void reportStatus() {
        System.out.println("Smart Door Lock Status:");
        System.out.println("- Name: " + deviceName);
        System.out.println("- Active: " + (isActive() ? "Yes" : "No"));
        System.out.println("- Locked: " + (isLocked() ? "Yes" : "No"));
        System.out.println("- Door Position: " + (doorOpen ? "Open" : "Closed"));
        System.out.println("- Battery Level: " + batteryLevel + "%");
        System.out.println("- Energy Rating: " + getEnergyEfficiencyRating() + "/5");
    }
    
    public void openDoor(String password) {
        if (doorOpen == true) {
            System.out.println("Door is already open");
            return;
        }
        
        if (isActive() == false) {
            System.out.println("Cannot open door: Device is not active");
            return;
        }
        
        if (isLocked() == true) {
            unlock(password);
            if (isLocked() == true) {
                return;
            }
        }
        
        doorOpen = true;
        useBattery(10);
        System.out.println("Door opened");
    }
    
    public void closeDoor() {
        if (doorOpen == false) {
            System.out.println("Door is already closed");
            return;
        }
        
        doorOpen = false;
        useBattery(5);
        System.out.println("Door closed");

        if (isActive() == true) {
            lock();
        }
    }
    
    public boolean isDoorOpen() {
        return doorOpen;
    }

    public void chargeBattery(int amount) {
        batteryLevel += amount;
        if (batteryLevel > MAX_BATTERY) {
            batteryLevel = MAX_BATTERY;
        }

        System.out.println("Battery charged to " + batteryLevel + "%");
    }

    private void useBattery(int amount) {
        batteryLevel -= amount;
        if (batteryLevel < 0) {
            batteryLevel = 0;
            System.out.println("Warning: Battery depleted, device turned off");
            turnOff();
        } else if (batteryLevel < 20) {
            System.out.println("Warning: Battery low (" + batteryLevel + "%)");
        }
    }
    
    public void turnOn() {
        if (batteryLevel <= 0) {
            System.out.println("Cannot turn on: Battery depleted");
            return;
        }
        
        super.turnOn();
        useBattery(5);
    }
    
    public void unlock(String password) {
        if (batteryLevel <= 0) {
            System.out.println("Cannot unlock: Battery depleted");
            return;
        }
        
        super.unlock(password);
        if (isLocked() == false) {
            useBattery(8);
        }
    }
}