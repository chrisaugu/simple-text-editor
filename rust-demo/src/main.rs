#![allow(unreachable_code, unused_labels)]

use crate::my_module::{MyCoolStruct};
use clap::Parser;

/// Search for a pattern in a file and display the lines that contain it.
#[derive(Parser)]
struct Cli {
    /// The pattern to look for
    pattern: String,
    /// The path to the file to read
    path: std::path::PathBuf,
}

mod my_module;

// use eframe::{egui, run_native};
//
// struct MyApp;
//
// impl eframe::App for MyApp {
//     fn update(&mut self, ctx: &egui::Context, _frame: &mut eframe::Frame) {
//         egui::CentralPanel::default().show(ctx, |ui| {
//             ui.heading("Hello, egui!");
//             if ui.button("Click me!").clicked() {
//                 println!("Button clicked!");
//             }
//         });
//     }
// }

fn some_function() {}

fn main() {
    println!("Hello, world!");

    // let x = some_function().unwrap();
    // let x = some_function().expect("some error message when panic occurs");
    let x: Result<i32, &str> = Ok(42); // Simulating a function that returns a Result

    let my_boolean_result = match x {
        Ok(x) => {
            println!("{} is a good variable!", x);
            true
        }
        Err(err) => {
            println!("Error: {}", err);
            false
        }
    };

    let pattern = std::env::args().nth(1).expect("no pattern given");
    let path = std::env::args().nth(2).expect("no path given");

    // let args = Cli {
    //     pattern,
    //     path: std::path::PathBuf::from(path.clone()),
    // };
    let args = Cli::parse();

    println!("pattern: {:?}, path: {:?}", args.pattern, args.path);

    // if let Ok(x) = some_function() {
    //     // logic that should only run if you get an OK result back
    // } else {
    //     // logic that should run if you don't get OK back
    // }

    // let options = eframe::NativeOptions::default();
    // run_native(
    //     "My egui App",
    //     options,
    //     Box::new(|_cc| Box::new(MyApp)),
    // ).unwrap();

    let x = 5 + 90 + 5;
    println!("Is `x` 10 or 100? x = {}", x);

    println!("Base 10:               {}", 69420); // 69420
    println!("Base 2 (binary):       {:b}", 69420); // 10000111100101100
    println!("Base 8 (octal):        {:o}", 69420); // 207454
    println!("Base 16 (hexadecimal): {:x}", 69420); // 10f2c

    let n = 5;

    if n < 0 {
        print!("{} is negative", n);
    } else if n > 0 {
        print!("{} is positive", n);
    } else {
        print!("{} is zero", n);
    }

    let big_n = if n < 10 && n > -10 {
        println!(", and is a small number, increase ten-fold");

        // This expression returns an `i32`.
        10 * n
    } else {
        println!(", and is a big number, halve the number");

        // This expression must return an `i32` as well.
        n / 2
        // TODO ^ Try suppressing this expression with a semicolon.
    };
    //   ^ Don't forget to put a semicolon here! All `let` bindings need it.

    println!("{} -> {}", n, big_n);

    let mut count = 0u32;

    println!("Let's count until infinity!");

    loop {
        count += 1;

        if count == 3 {
            println!("three");

            continue;
        }

        println!("{}", count);

        if count == 5 {
            println!("OK, that's enough");

            // Exit this loop
            break;
        }
    }

    'outer: loop {
        println!("Entered the outer loop");

        'inner: loop {
            println!("Entered the inner loop");

            // This would break only the inner loop
            //break;

            // This breaks the outer loop
            break 'outer;
        }

        println!("This point will never be reached");
    }

    println!("Exited the outer loop");
}
