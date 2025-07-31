use std::io; // Import the io module
use std::cmp::Ordering;
use rand::Rng;
use colored::*;

fn main() {
    let secret_number = rand::thread_rng().gen_range(1, 101); // High is exclusive. It generates a random number between 1 and 100

    println!("The random guess is: {}", secret_number);

    loop {
        println!("Guess the number!");

        let mut guess = String::new(); // Type inference can often handle String::new()

        println!("Please input your guess.");
        io::stdin()
            .read_line(&mut guess) // Correct way to call read_line
            .expect("Failed to read line"); // Correct way to call expect

        let guess: u32 = match guess.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        }; // this is shadowing

        println!("You guessed: {}", guess);

        match guess.cmp(&secret_number) {
            Ordering::Less => println!("{}", "Too small!".red()),
            Ordering::Greater => println!("{}", "Too big!".red()),
            Ordering::Equal => {
                println!("{}", "You win!".green());
                break;
            },
        }
    }
}
