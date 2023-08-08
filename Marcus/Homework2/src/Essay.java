/**
    A class that holds a grade for a graded activity.
*/

class GradedActivity
{
    private double score; // Numeric score

    /**
        The setScore method sets the score field.
        @param s The value to store in score.
    */

    public void setScore(double s)
    {
        score = s;
    }

    /**
        The getScore method returns the score.
        @return The value stored in the score field.
    */

    public double getScore()
    {
        return score;
    }

    /**
        The getGrade method returns a letter grade
        determined from the score field.
        @return The letter grade.
    */

    public char getGrade()
    {
        char letterGrade;

        if (score >= 90)
            letterGrade = 'A';
        else if (score >= 80)
            letterGrade = 'B';
        else if (score >= 70)
            letterGrade = 'C';
        else if (score >= 60)
            letterGrade = 'D';
        else
            letterGrade = 'F';

        return letterGrade;
    }
}


class Essay extends GradedActivity {
    private int grammarPoints;
    private int spellingPoints;
    private int lengthPoints;
    private int contentPoints;

    public Essay(int grammarPoints, int spellingPoints, int lengthPoints, int contentPoints) {
        this.grammarPoints = grammarPoints;
        this.spellingPoints = spellingPoints;
        this.lengthPoints = lengthPoints;
        this.contentPoints = contentPoints;
    }

    public void calculateScore() {
        double total = grammarPoints + spellingPoints + lengthPoints + contentPoints;
        super.setScore(total);
    }

    public void generateRandomPoints() {
        java.util.Random random = new java.util.Random();
        int randomGrammar = random.nextInt(grammarPoints + 1);
        int randomSpelling = random.nextInt(spellingPoints + 1);
        int randomLength = random.nextInt(lengthPoints + 1);
        int randomContent = random.nextInt(contentPoints + 1);

        System.out.println("Random Grammar Points: " + randomGrammar);
        System.out.println("Random Spelling Points: " + randomSpelling);
        System.out.println("Random Correct Length Points: " + randomLength);
        System.out.println("Random Content Points: " + randomContent);

        double total = randomGrammar + randomSpelling + randomLength + randomContent;
        super.setScore(total);
    }
}
