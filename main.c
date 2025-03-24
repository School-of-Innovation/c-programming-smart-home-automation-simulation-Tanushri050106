/*
 * 🚨 WARNING: CHALLENGE MODE ACTIVATED 🚨
 * 
 * 1️⃣ Sit back, take a deep breath, and **THINK**.
 * 2️⃣ For the next **10 minutes**, avoid using **Gen AI, ChatGPT, or any shortcuts**.
 * 3️⃣ Trust your **brain**—you’re smarter than you think!
 * 4️⃣ Consider yourself a **LOSER** if you cheat. Seriously, promise yourself you won't. 😤
 * 5️⃣ If you solve it on your own, **you WIN** and level up as a true programmer and come and meet me ! 
 * 
 * 
 * 💡 Remember: The best coders aren’t the ones who copy-paste. They are the ones who **struggle, think, fail, and then succeed.** 
 *    
 * Now, write your code! You got this! 💪🔥
 */

 #include <stdio.h>
 
 #define MAX_ROOMS 5  // Max number of rooms
 
 // Function prototypes
 void initializeSystem(int room, int light[], int temp[], int motion[], int door_lock[]);
 void displayMenu();
 void controlLights(int room, int light[]);
 void readTemperature(int room, int temp[]);
 void detectMotion(int room, int motion[]);
 void securitySystem(int room, int door_lock[]);
 void analyzeHouseStatus(int room, int light[], int temp[], int motion[], int door_lock[]);
 
 int main() {
    
     int room, choice;
     printf("Enter the Number of Rooms : ");
     scanf("%d", &room);
 
     // Validate room count
     if (room > MAX_ROOMS || room < 1) {
         printf("Invalid number of rooms. Exiting.\n");
         return 1; // Exit the program with error
     }
 
     int light[room], temp[room], motion[room], door_lock[room];
 
     // Initialize system
     initializeSystem(room, light, temp, motion, door_lock);
 
     do {
         displayMenu();
         printf("Enter your Choice: ");
         scanf("%d", &choice);
 
         switch (choice) {
             case 1:
                 controlLights(room, light);
                 break;
 
             case 2:
                 readTemperature(room, temp);
                 break;
 
             case 3:
                 detectMotion(room, motion);
                 break;
 
             case 4:
                 securitySystem(room, door_lock);
                 break;
 
             case 5:
                 analyzeHouseStatus(room, light, temp, motion, door_lock);
                 break;
 
             case 6:
                 printf("Exiting... Goodbye!\n");
                 break;
 
             default:
                 printf("Invalid choice. Please enter a valid option.\n");
         }
 
     } while (choice != 6);
 
     return 0;
 }
 
 void initializeSystem(int room, int light[], int temp[], int motion[], int door_lock[]) {
     for (int i = 0; i < room; i++) {
         light[i] = 0;
         temp[i] = 23 + i; // Sample initial temperatures
         motion[i] = 0;
         door_lock[i] = 1; // Locked by default
     }
     printf("System Initialized for %d room(s).\n", room);
 }
 
 void displayMenu() {
     printf("\n===== Smart Home Menu =====\n");
     printf("1. Toggle Light\n");
     printf("2. Read Temperature\n");
     printf("3. Check Motion Sensor\n");
     printf("4. Lock/Unlock Security System\n");
     printf("5. House Status Summary\n");
     printf("6. Exit\n");
 }
 
 void controlLights(int room, int light[]) {
     int t_room;
     printf("Enter room number to toggle light (1-%d): ", room);
     scanf("%d", &t_room);
 
     if (t_room < 1 || t_room > room) {
         printf("Invalid room number.\n");
         return;
     }
 
     light[t_room - 1] = !light[t_room - 1];
     printf("Light in Room %d is now %s.\n", t_room, light[t_room - 1] ? "ON" : "OFF");
 }
 
 void readTemperature(int room, int temp[]) {
     int t_room;
     printf("Enter room number to read temperature (1-%d): ", room);
     scanf("%d", &t_room);
 
     if (t_room < 1 || t_room > room) {
         printf("Invalid room number.\n");
         return;
     }
 
     printf("Temperature in Room %d: %d°C\n", t_room, temp[t_room - 1]);
     if (temp[t_room - 1] > 30) {
         printf("Warning: Temperature in Room %d is above 30°C!\n", t_room);
     }
 }
 
 void detectMotion(int room, int motion[]) {
     int t_room;
     printf("Enter room number to check motion sensor (1-%d): ", room);
     scanf("%d", &t_room);
 
     if (t_room < 1 || t_room > room) {
         printf("Invalid room number.\n");
         return;
     }
 
     printf("Motion in Room %d: %s\n", t_room, motion[t_room - 1] ? "Detected" : "No Motion");
 }
 
 void securitySystem(int room, int door_lock[]) {
     int t_room;
     printf("Enter room number to lock/unlock (1-%d): ", room);
     scanf("%d", &t_room);
 
     if (t_room < 1 || t_room > room) {
         printf("Invalid room number.\n");
         return;
     }
 
     door_lock[t_room - 1] = !door_lock[t_room - 1];
     printf("Room %d is now %s.\n", t_room, door_lock[t_room - 1] ? "Locked" : "Unlocked");
 }
 
 void analyzeHouseStatus(int room, int light[], int temp[], int motion[], int door_lock[]) {
     printf("\nHouse Status:\n");
     for (int i = 0; i < room; i++) {
         printf("- Room %d: Light %s, Temp %d°C, %s, %s\n",
                i + 1,
                light[i] ? "ON" : "OFF",
                temp[i],
                motion[i] ? "Motion Detected" : "No Motion",
                door_lock[i] ? "Locked" : "Unlocked");
     }
 }