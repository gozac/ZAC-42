using UnityEngine;
using System.Collections;

public class scoringshadow : MonoBehaviour {

	public string nextlvlname;

	public string helper;

	public int score = 1;

	private int actualscr = 0;

	void addscore () {
		actualscr++;
	}

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
	
	}

	void OnGUI (){
		if (helper != null) {
			GUI.Box (new Rect (3, 3, 260, 27), helper);
		}
		if (actualscr == score) {
			GUI.Box (new Rect (Screen.width / 2 - 130, Screen.height / 2 - 90, 260, 140), "Félicitation vous avez réussi le niveau");
			if (GUI.Button (new Rect (Screen.width / 2 - 25, Screen.height / 2 - 20, 50, 40), "OK")){
				PlayerPrefs.SetInt(Application.loadedLevelName, 2);
				if (PlayerPrefs.GetInt(nextlvlname) == 0)
					PlayerPrefs.SetInt(nextlvlname, 1);
				PlayerPrefs.Save ();
				Application.LoadLevel("menu");
			}
		}
	}
}
