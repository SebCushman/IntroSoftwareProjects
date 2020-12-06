

public static int promptForInt(String prompt, int min, int max) {
    if (max < min) {
        throw new IllegalArgumentException("The min cannot be greater than the max");
    }
    else {
        int userNum = 0;
        boolean isInvalid = true;

        do {
            String input = promptForString(prompt);

            try {
                userNum = Integer.parseInt(input);
                isInvalid = userNum < min || userNum > max;
            }
            catch (NumberFormatException var7) {
            }

            if (isInvalid) {
                System.out.println("You must enter a number between " + min + " and " + max + ". Please, try again.");
            }
        } while (isInvalid);

        return userNum;
    }
}

public static boolean promptForBoolean(String prompt, String trueString, String falseString) {
    if (trueString != null && falseString != null && !trueString.trim().isEmpty() && !falseString.trim().isEmpty() && !trueString.trim().equalsIgnoreCase(falseString.trim())) {
        trueString = trueString.trim();
        falseString = falseString.trim();
        boolean isInvalid = true;
        boolean isTrue = false;

        do {
            String input = promptForString(prompt).trim();
            isInvalid = !input.equalsIgnoreCase(trueString) && !input.equalsIgnoreCase(falseString);
            if (isInvalid) {
                System.out.println("You must input either \"" + trueString + "\" or \"" + falseString + "\". Try again");
            }
            else {
                isTrue = input.equalsIgnoreCase(trueString);
            }
        } while (isInvalid);

        return isTrue;
    }
    else {
        throw new IllegalArgumentException("the true string and false string values cannot be nul empty, whitespace-only, or the same");
    }
}

public static int promptForMenuSelection(String[] options, boolean withQuit, @Nullable String quitString) {
    if (options == null) {
        options = new String[0];
    }

    if (options.length == 0 && !withQuit) {
        throw new IllegalArgumentException("There must be at least one menu option to select");
    }
    else {
        int selection = true;
        int min = withQuit ? 0 : 1;
        int max = options.length;
        StringBuilder bob = new StringBuilder("Please, choose one of the following\n\n");

        for (int i = 0; i < options.length; ++i) {
            bob.append(i + 1).append(": ").append(options[i]).append("\n");
        }

        if (options.length > 0) {
            bob.append("\n");
        }

        if (withQuit) {
            if (quitString == null) {
                quitString = "Quit";
            }

            bob.append("0: " + quitString + "\n\n");
        }

        bob.append("\nSelection: ");
        int selection = promptForInt(bob.toString(), min, max);
        return selection;
    }
}