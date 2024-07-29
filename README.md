# Car-Parking-Problem
This is a car parking problem in a grid. The goal is to take all the cars out of the grid using the Breadth First Search algorithm.

[Εργασία1.docx](https://github.com/user-attachments/files/16419387/1.docx)

The grid is 3 by 4.
- | : vertical oriented car
- \- : horizontal oriented car
- Χ : obstacle
- O : empty cell

<pre>
  ex:
    
      *****INITIAL BOARD*****
      O  O  O  O  
      X  -  O  O  
      |  O  O  O  
      
      BFS STARTED...
      Problem not yet solved!
      EXPAND this state: 
      O  O  O  O  
      X  -  O  O  
      |  O  O  O  
      
      Trying moving up...
      Couldn't make the move!
      
      Trying moving down...
      Move down done
      O  O  O  O  
      X  -  O  O  
      O  O  O  O  
      
      Trying moving right...
      Move right done
      O  O  O  O  
      X  O  -  O  
      |  O  O  O  
      
      Trying moving left...
      Couldn't make the move!
      
      --------------------------------------------
      
      Problem not yet solved!
      EXPAND this state: 
      O  O  O  O  
      X  -  O  O  
      O  O  O  O  
      
      Trying moving right...
      Move right done
      O  O  O  O  
      X  O  -  O  
      O  O  O  O  
      
      Trying moving left...
      Couldn't make the move!
      
      --------------------------------------------
      
      Problem not yet solved!
      EXPAND this state: 
      O  O  O  O  
      X  O  -  O  
      |  O  O  O  
      
      Trying moving up...
      Couldn't make the move!
      
      Trying moving down...
      Move down done
      O  O  O  O  
      X  O  -  O  
      O  O  O  O  
      
      Trying moving right...
      Move right done
      O  O  O  O  
      X  O  O  -  
      |  O  O  O  
      
      Trying moving left...
      Move left done
      O  O  O  O  
      X  -  O  O  
      |  O  O  O  
      
      --------------------------------------------
      
      Problem not yet solved!
      EXPAND this state: 
      O  O  O  O  
      X  O  -  O  
      O  O  O  O  
      
      Trying moving right...
      Move right done
      O  O  O  O  
      X  O  O  -  
      O  O  O  O  
      
      Trying moving left...
      Move left done
      O  O  O  O  
      X  -  O  O  
      O  O  O  O  
      
      --------------------------------------------
      
      Problem not yet solved!
      EXPAND this state: 
      O  O  O  O  
      X  O  O  -  
      |  O  O  O  
      
      Trying moving up...
      Couldn't make the move!
      
      Trying moving down...
      Move down done
      O  O  O  O  
      X  O  O  -  
      O  O  O  O  
      
      Trying moving right...
      Move right done
      O  O  O  O  
      X  O  O  O  
      |  O  O  O  
      
      Trying moving left...
      Move left done
      O  O  O  O  
      X  O  -  O  
      |  O  O  O  
      
      --------------------------------------------
      
      Problem not yet solved!
      EXPAND this state: 
      O  O  O  O  
      X  O  O  -  
      O  O  O  O  
      
      Trying moving right...
      Move right done
      O  O  O  O  
      X  O  O  O  
      O  O  O  O  
      
      Trying moving left...
      Move left done
      O  O  O  O  
      X  O  -  O  
      O  O  O  O  
      
      --------------------------------------------
      
      Problem not yet solved!
      EXPAND this state: 
      O  O  O  O  
      X  O  O  O  
      |  O  O  O  
      
      Trying moving up...
      Couldn't make the move!
      
      Trying moving down...
      Move down done
      O  O  O  O  
      X  O  O  O  
      O  O  O  O  
      
      --------------------------------------------
      
      Problem solved!
      *****FINAL BOARD*****
      O  O  O  O  
      X  O  O  O  
      O  O  O  O  
      
      Mem: 9, Examined: 8
</pre>

