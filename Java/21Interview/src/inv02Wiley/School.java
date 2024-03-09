package inv02Wiley;

import java.util.ArrayList;
import java.util.List;

public class School {
    Student std;
    public void printStd(){
        std = new Student();
        Student.printName();
        int[] IDs = new int[5];
        for(int i=0;i<IDs.length;++i){
            IDs[i] = i+1;
        }

        List<Student> stdList = new ArrayList<>();
        stdList.add(std);
        SELECT age FROM student Where id==1;
        SELECT * FROM student JOIN course ON student.id = course.id WHERE duration=30;
    }
}
