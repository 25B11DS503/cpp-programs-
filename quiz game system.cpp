# Quiz Game System

questions = [
    {
        "question": "What is the capital of France?",
        "options": ["A. Berlin", "B. Madrid", "C. Paris", "D. Rome"],
        "answer": "C"
    },
    {
        "question": "Which planet is known as the Red Planet?",
        "options": ["A. Earth", "B. Mars", "C. Jupiter", "D. Venus"],
        "answer": "B"
    },
    {
        "question": "Who developed Python?",
        "options": ["A. James Gosling", "B. Dennis Ritchie", "C. Guido van Rossum", "D. Bjarne Stroustrup"],
        "answer": "C"
    },
    {
        "question": "What is 10 + 15?",
        "options": ["A. 20", "B. 25", "C. 30", "D. 35"],
        "answer": "B"
    },
    {
        "question": "Which language is used for web page structure?",
        "options": ["A. HTML", "B. Python", "C. Java", "D. C++"],
        "answer": "A"
    }
]

score = 0

print("=" * 40)
print("       Welcome to the Quiz Game")
print("=" * 40)

for i, q in enumerate(questions, start=1):
    print(f"\nQuestion {i}: {q['question']}")
    for option in q["options"]:
        print(option)

    user_answer = input("Enter your answer (A/B/C/D): ").strip().upper()

    if user_answer == q["answer"]:
        print("? Correct!")
        score += 1
    else:
        print(f"? Wrong! Correct answer is {q['answer']}.")

print("\n" + "=" * 40)
print("Quiz Completed!")
print(f"Your Score: {score}/{len(questions)}")

percentage = (score / len(questions)) * 100
print(f"Percentage: {percentage:.2f}%")

if percentage >= 80:
    print("?? Excellent!")
elif percentage >= 60:
    print("?? Good Job!")
elif percentage >= 40:
    print("?? Keep Practicing!")
else:
    print("?? Better Luck Next Time!")

print("=" * 40)
