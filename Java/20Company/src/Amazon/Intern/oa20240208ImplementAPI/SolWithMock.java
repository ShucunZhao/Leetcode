package Amazon.Intern.oa20240208ImplementAPI;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class SolWithMock {
    private final Map<String, String> userDatabase = new HashMap<>();
    private final Map<String, Boolean> userLoggedIn = new HashMap<>();
    public String register(String username, String password) {
        if (userDatabase.containsKey(username)) {
            return "Registration Unsuccessful";
        } else {
            userDatabase.put(username, password);
            userLoggedIn.put(username, false);
            return "Registered Successfully";
        }
    }
    public String login(String username, String password) {
        if (!userDatabase.containsKey(username) || !userDatabase.get(username).equals(password)) {
            return "Login Unsuccessful";
        } else if (userLoggedIn.get(username)) {
            return "Login Unsuccessful - User Already Logged In";
        } else {
            userLoggedIn.put(username, true);
            return "Logged In Successfully";
        }
    }
    public String logout(String username) {
        if (userLoggedIn.getOrDefault(username, false)) {
            userLoggedIn.put(username, false);
            return "Logged Out Successfully";
        } else {
            return "Logout Unsuccessful - User Not Logged In";
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        SolWithMock system = new SolWithMock();

        int n = Integer.parseInt(scanner.nextLine());
        String[] results = new String[n];

        for (int i = 0; i < n; i++) {
            String[] input = scanner.nextLine().split(" ");
            String action = input[0];
            String username = input[1];
            String password = input.length > 2 ? input[2] : null;

            switch (action) {
                case "register":
                    results[i] = system.register(username, password);
                    break;
                case "login":
                    results[i] = system.login(username, password);
                    break;
                case "logout":
                    results[i] = system.logout(username);
                    break;
                default:
                    results[i] = "Invalid Action";
                    break;
            }
        }
        for (String result : results) { System.out.println(result); }
        scanner.close();
    }
}
