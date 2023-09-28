#include <algorithm>
#include <ctime>
#include <iostream>
#include <memory>
#include <random>
#include <string>
#include <vector>

// Tutorial from David Plummer https://github.com/davepl/blackjack
// Dynamic array allocation
// No more manual memory allocation
// Ownership semantics - avoids double deletion, memory leaks
// Automatic memory management
// Custom deleterstype

enum Rank {
  ACE = 1,
  TWO,
  THREE,
  FOUR,
  FIVE,
  SIX,
  SEVEN,
  EIGHT,
  NINE,
  JACK,
  QUEEN,
  KING
};

enum Suit { HEARTS, DIAMONDS, CLUBS, SPADES };

// Card with a rank and suit
class Card {
public:
  // Constructor
  Card(Rank rank, Suit suit) : rank_(rank), suit_(suit) {}

  // Getters
  Rank getRank() const { return rank_; }
  Suit getSuit() const { return suit_; }

private:
  // Only knows its own rank and suit
  Rank rank_;
  Suit suit_;
};

// Deck of cards, generated at constructor
class Deck {
public:
  Deck() {
    for (int suit = HEARTS; suit <= SPADES; suit++) { // For each suit
      for (int rank = ACE; rank <= KING; rank++) {    // For each rank
        // Put a card into the deck that grows in size dynamically, and when
        // removed shrinks in size dynamically with unique pointers
        cards_.push_back(std::make_unique<Card>(static_cast<Rank>(rank),
                                                static_cast<Suit>(suit)));
        // std::cout << rank << " of " << suit << std::endl;
      }
    }
  }
  void shuffle_deck() {
    std::random_device rd;
    std::mt19937 g(rd()); // Number of cards generated more than the amount of
                          // electrons in the universe
    std::shuffle(cards_.begin(), cards_.end(),
                 g); // Shuffles with the random generation
  }

  std::unique_ptr<Card> drawCard() {
    if (cards_.empty()) {
      return nullptr;
    }
    std::unique_ptr<Card> card =
        std::move(cards_.back()); // Draw a card from the back, take pointers
                                  // ownership out of Deck
    cards_.pop_back();
    return card;
  }

private:
  std::vector<std::unique_ptr<Card>> cards_; // Set of cards in a deck
};

class Player {
public:
  void addCard(std::unique_ptr<Card> card) { hand_.push_back(std::move(card)); }

  int getHandValue() const {
    int value = 0;
    int aces = 0;
    for (const auto &card : hand_) { // For every card in your hand
      int cardValue = card->getRank();
      if (cardValue >= 10) { // All face cards are worth 10
        cardValue = 10;
      } else if (cardValue == ACE) {
        aces++;
        cardValue = 11;
      }
      value += cardValue;
    }
    while (value > 21 && aces > 0) {
      value -= 10;
      aces--;
    }
    return value;
  }

private:
  std::vector<std::unique_ptr<Card>> hand_;
};

int main() {
  Deck deck;
  deck.shuffle_deck();

  Player player;
  Player dealer;

  player.addCard(deck.drawCard());
  player.addCard(deck.drawCard());

  dealer.addCard(deck.drawCard());
  dealer.addCard(deck.drawCard());

  std::cout << "Player Value: " << player.getHandValue() << std::endl;
  std::cout << "Dealer Value: " << dealer.getHandValue() << std::endl;

  if (player.getHandValue() == dealer.getHandValue()) {
    std::cout << "It's a push! (tie)\n";
    return 0;
  }
  if (player.getHandValue() == 21) {
    std::cout << "Player wins by Blackjack!\n";
    return 0;
  }
  if (dealer.getHandValue() == 21) {
    std::cout << "Dealer wins by Backjack!\n";
    return 0;
  }
  if (player.getHandValue() > dealer.getHandValue()) {
    std::cout << "Player wins!\n";
    return 0;
  }
  std::cout << "Dealer wins!\n";
  return 0;
}