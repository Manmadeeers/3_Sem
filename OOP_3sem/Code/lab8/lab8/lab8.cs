using Microsoft.VisualBasic;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace lab8
{
    public class Game
    {
        public Game() { }
        public delegate void MovementDelegate(int movement_rate);
        public event MovementDelegate? OnMove;
        public delegate void CompressionDelegate(double compression_rate);
        public event CompressionDelegate? OnCompressed;

        public void MoveUser(int movement, char axis)
        {
            if (movement == 0 || movement < 0)
            {
                Console.WriteLine("User wasn't moved");
            }
            if (axis == 'X' || axis == 'x')
            {

                Console.WriteLine($"User was moved on {movement} by axis {axis}");
                OnMove?.Invoke(movement);
            }
            else if (axis == 'Y' || axis == 'y')
            {
                Console.WriteLine($"User was moved on {movement} by axis {axis}");
                OnMove?.Invoke(movement);
            }
            else
            {
                throw new ArgumentException("Invalid axis exception was called");
            }
        }
    }
    public class User
    {
        private string _name;
        private int _positionX = 0;
        private int _positionY = 0;
        private double _comprassion_rate = 0;
        public string Name
        {
            get { return _name; }
        }

        public User() { }
        public User(string name)
        {
            _name = name;
        }


        public delegate void MovementDelegate(int movement_rate);
        public event MovementDelegate ? OnMove;
        public delegate void CompressionDelegate(double compression_rate);
        public event CompressionDelegate ? OnCompressed;

        public void HandleMove(int movement,char axis)
        {
            if (axis == 'X' || axis == 'x')
            {
                _positionX += movement;
                Console.WriteLine($"User named {Name} was moved on {movement} by axis {axis}");
                Console.WriteLine($"Now {Name} position is X:{_positionX},Y:{_positionY}");
            }
            else if (axis == 'Y' || axis == 'y')
            {
                _positionY += movement;
                Console.WriteLine($"User named {Name} was moved on {movement} by axis {axis}");
                Console.WriteLine($"Now {Name} position is X:{_positionX},Y:{_positionY}");
            }
            else
            {
                throw new ArgumentException("Invalid axis exception was called");
            }
        }
        public void HandleCompression(double compression_rate)
        {
            if(compression_rate < 0)
            {
                throw new ArgumentException("Compression rate below zero");
            }
            else
            {
                _comprassion_rate = compression_rate;
                Console.WriteLine($"User {Name} was compressed by compression rate {compression_rate}");
            }
        }


    }

}
