<?php
$de_inlocuit = '1'; // exactly what you want to replace
$nr_start = 1; // from which number do you start counting
$cale_fisiere = getcwd();

// excluded files
$fisiere_excluse = array(  
	'.htaccess',
	'robots.txt',
	'.ftpquota',
	'about.html',
	'y_key_e479323ce281e459.html',
	'yandex_46f3adbe1b25a4ca.html',
	'test4.html',
	'search.html',
	'inlocuire.php',
);

$lista_fisiere = get_list_dir($cale_fisiere, false, 'file', true, $fisiere_excluse);
if ( is_array($lista_fisiere) && count($lista_fisiere)) {
	// sortam lista de fisiere
	natsort($lista_fisiere);
	//echo '<pre>'.var_export($lista_fisiere,1).'</pre>';
	foreach($lista_fisiere as $fisier) {
		$continut_original = file_get_contents($fisier);
		// cautam in fisier bucata de inlocuit
		if ( stristr($continut_original, $de_inlocuit) ) {
			// daca a gasit, inlocuieste
			$continut_modificat = str_replace($de_inlocuit, $nr_start, $continut_original);
			// scoatem randurile goale
			$continut_modificat = str_replace("\n\n\n\n", "\n\n", $continut_modificat);
			// salvam continutul inapoi in fisier
			$is_saved = file_put_contents($fisier, $continut_modificat);
			if ( ! $is_saved ) {
				die('Eroare: Nu sa putut modifica fisierul '.$fisier.'. Am ramas la numarul '.$nr_start);
			}
			$nr_start++;
		}
	}
	echo 'Au fost verificate '.count($lista_fisiere).' fisiere si ultimul numar este '.($nr_start - 1);
} else {
	echo 'Nu au fost gasite fisiere, verificati calea fisierelor';
}

/*
 * get list of directory specified
 *
 * @Author: Birkoff - www.tutorialeonline.net
 * 
 * @param str $path - path where to start reading the directories and files
 * @param bool $depth - 
 * 		'true' if you read each subdirectory found in part or 
 * 		'false' if you only read the path specified (not subdirectory)
 * @param str $type - 
 * 		'all' - returns all files and directories found, 
 * 		'dir' - only returns the list of directories found, 
 * 		'file' - only returns the list of files found
 * @param bool $inc - 
 * 		'true' if desired path and file to that folder / file or 
 * 		'false' returns only if the file name without the path to it
 * @param array $exclude - an array of files that can be excluded
 *
 * @Created by Birkoff for www.tutorialeonline.net 
 * @return array $list - an array containing numeric values as keys and the 
 *  		path / filename as values (depending on the setting parameter $inc)
 */
function get_list_dir($path, $depth = false, $type = 'all', $inc = true, $exclude = array(), $max=95) {
    // Set list
    $list = array();
    // directory element is determined depending on the operating system
    $elm = ( stristr(PHP_OS, 'win') === false ) ? '/' : '\\';
    if (empty($path))
        return false;
    if (!is_dir($path))
        return false;
    // memorizes the current path
    $base_path = getcwd();
    // change to the path specified
    if ($base_path != $path) {
        $is_changed = chdir($path);
        if (!$is_changed)
            return false;
    }
    $required_path = getcwd();
    if (!$required_path)
        return false;
    // read path required
    $director = opendir($required_path);
    if (!$director) {
        // return to the base path
        chdir($base_path);
        return false;
    }
    // reads the current directory
    $read = readdir($director);
    if ($read === false) {
        // return to the base path
        chdir($base_path);
        return false;
    }
    while ($read) {
        // excluding files / directories unwanted
        if (!in_array($read, $exclude)) {
            // check what type is required
            switch ($type) {
                default:
                case 'all': // returns all files and directories found
                    // to memorize what is currently
                    $list[] = ( $inc ) ? $required_path . $elm . $read : $read;
                    // if is director and requires completion
                    if (is_dir($read) && $depth) {
                        if ( $max<1) {
                            $list[] = 'Too many subdirectories, indexing interrupted.';
                            break;
                        } else {
                            // browse the directory
                            $x = get_list_dir($read, $depth, $type, $inc, $exclude, $max-1);
                            $list = array_merge($list,$x);
                        }
                    }
                    break;
                case 'dir': // only returns the list of directories found
                    // if is director
                    if (is_dir($read)) {
                        // to memorize what is currently
                        $list[] = ( $inc ) ? $required_path . $elm . $read : $read;
                        // if requires completion
                        if ($depth) {
                            if ( $max<1) {
                                $list[] = 'Too many subdirectories, indexing interrupted.';
                                break;
                            } else {
                                // browse the directory
                                $x = get_list_dir($read, $depth, $type, $inc, $exclude, $max-1);
                                $list = array_merge($list,$x);
                            }
                        }
                    }
                    break;
                case 'file': // only returns the list of files found
                    // check if file
                    if (is_file($read)) {
                        // to memorize what is currently
                        $list[] = ( $inc ) ? $required_path . $elm . $read : $read;
                    }
                    // else if is folder and it requires completion
                    elseif ($depth) {
                        if ( $max<1) {
                            $list[] = 'Too many subdirectories, indexing interrupted.';
                            break;
                        } else {                        
                            // browse the directory
                            $x = get_list_dir($read, $depth, $type, $inc, $exclude, $max-1);
                            $list = array_merge($list,$x);
                        }
                    }
                    break;
            } // end switch 
        } // end exclude
        // go to next
        $read = readdir($director);
    } // end while
    // director closes
    closedir($director);
    // returns to the initial path
    chdir($base_path);
    // return
    return $list;
}

?>