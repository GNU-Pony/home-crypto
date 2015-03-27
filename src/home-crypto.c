/**
 * home-crypto – A solution for encrypted home directories
 * 
 * Copyright © 2015  Mattias Andrée (maandree@member.fsf.org)
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


/**
 * The name of the command the process is running as
 */
static char* execname;



/**
 * Here we go!
 * 
 * @param   argc  The number of command line arguments
 * @param   argv  The command line arguments
 * @return        Zero on and only on success
 */
int main(int argc, char** argv)
{
  char* action;
  
  if (argc == 0)
    abort();
  
  execname = *argv;
  action = argc > 1 ? argv[1] : NULL;
  
  if ((argc == 1) || ((argc == 2) &&
		      (strcmp(argv[1], "help") || strcmp(argv[1], "-help") ||
		       strcmp(argv[1], "--help") || strcmp(argv[1], "-h"))))
    {
      FILE* f = argc == 1 ? stderr : stdout;
      
      fprintf(f, "SYNTAX: %s <action> (--help | <options>...)\n", execname);
      fprintf(f, "\n");
      fprintf(f, "ACTIONS:\n");
      fprintf(f, "  help           Print help about an action\n");
      fprintf(f, "  login          \n"); /* TODO */
      fprintf(f, "  create         \n"); /* TODO cryptsetup luksFormat && (list)  */
      fprintf(f, "  destroy        \n"); /* TODO cryptsetup luksErase && (unlist) */
      fprintf(f, "  open           \n"); /* TODO cryptsetup luksOpen              */
      fprintf(f, "  close          \n"); /* TODO cryptsetup close                 */
      fprintf(f, "  suspend        \n"); /* TODO cryptsetup luksSuspend           */
      fprintf(f, "  resume         \n"); /* TODO cryptsetup luksResume            */
      fprintf(f, "  format         \n"); /* TODO cryptsetup luksFormat && mkfs    */
      fprintf(f, "  reencrypt      \n"); /* TODO cryptsetup-reencrypt             */
      fprintf(f, "  changeKey      \n"); /* TODO cryptsetup luksChangeKey         */
      fprintf(f, "  headerBackup   \n"); /* TODO cryptsetup luksHeaderBackup      */
      fprintf(f, "  headerRestore  \n"); /* TODO cryptsetup luksHeaderRestore     */
      
      return argc == 1;
    }
  
  return 0;
}

