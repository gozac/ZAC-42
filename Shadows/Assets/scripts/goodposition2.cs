using UnityEngine;
using System.Collections;

public class goodposition2 : MonoBehaviour {

	private bool onclick = false;

	public KeyCode activekey;

	public bool govert = false;

	// Use this for initialization
	void Start () {
	
	}

	void OnMouseDown() {
			onclick = true;
	}

	// Update is called once per frame
	void Update () {
		if (onclick && Input.GetKeyUp (KeyCode.Mouse0)) {
			onclick = false;
		}
		else if (onclick && (Input.GetKey(activekey) || activekey == KeyCode.None)) {
			float h = -10f * Input.GetAxis("Mouse X");
			float v = -10f * Input.GetAxis("Mouse Y");
			transform.Translate(h * Time.deltaTime, 0, 0, null);
			if (govert)
				transform.Translate(0, -v * Time.deltaTime, 0, null);
		}
	}	
}
