struct Point {
  int i, j;
};

enum class GameDifficulty
{
  Easy,
  Medium,
  Hard
};

enum class MenuPosition
{
  Height,
  Width,
  Difficulty,
  Start,
  Return
};

struct MineSweeperDTO
{
  int height;
  int width;
  GameDifficulty difficulty;

  MineSweeperDTO() :
    height(0),
    width(0),
    difficulty(GameDifficulty::Easy)
  {}
};

class MineSweeper
{
public:
  static int min_height;
  static int min_width;
  static int max_height;
  static int max_width;

private:

  int lines;
  int columns;
  int mines;
  char **cells;
  char **curtain;
  bool **checked;
  int n_checked;
  bool locked;
  Point cursor;

public:

  MineSweeper(MineSweeperDTO);

  static void menu();
  static void play(MineSweeperDTO);

  void move_up();
  void move_down();
  void move_left();
  void move_right();
  void check();
  void curtain_set();

private:
  static void print_menu(WINDOW*, MenuPosition, MineSweeperDTO);
  static void destroy_menu(WINDOW*);
};
